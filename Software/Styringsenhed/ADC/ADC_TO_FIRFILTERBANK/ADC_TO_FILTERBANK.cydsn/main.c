//C KODE PRIMÆRT FRA https://dspguru.com/dsp/tricks/fir-filtering-in-c/
//KOEFFICIENTER FRA MATLAB FILTERDESIGNER
//INITIALISERING AF DMA FRA DMA WIZARD TOOL
//PING PONG BUFFER INSPIRATION FRA CYPRESS AN44011 https://www.cypress.com/file/44011/download

#include "project.h"
#include <stdio.h>
#include <string.h>
#include "fir_filter1.h"

/*Antal samples for hver DMA overførsel, 
skal stemme overens med max_input_len i fir_filter1.h*/
#define NO_OF_SAMPLES 80 

//Samme bliver brugt til begge kanaler
//*2 for 16 bit
#define TRANSFER_COUNT NO_OF_SAMPLES*2
//2 for 16 bit
#define DMA_BYTES_PER_BURST 2
#define DMA_REQUEST_PER_BURST 1
#define DMA_SRC_BASE (CYDEV_PERIPH_BASE)
#define DMA_DST_BASE (CYDEV_SRAM_BASE)

//FILTERKOEFFICIENTER
//KONVERTERES TIL INT16 I MATLAB VED KOEFF_VEK=int16(rec1_4.Numerator*2^15);
//HVOR FILTRET ER DESIGNET I FILTERDESIGNER, SKREVET TIL FUNKTION.

//FILTER 1
#define FILTER_LEN 64
static int16_t coeffs[ FILTER_LEN ] =
{-1468, 1058,   594,   287,    186,  284,   485,   613,
   495,   90,  -435,  -762,   -615,   21,   821,  1269,
   982,    9, -1132, -1721,  -1296,    1,  1445,  2136,
  1570,    0, -1666, -2413,  -1735,   -2,  1770,  2512,
  1770,   -2, -1735, -2413,  -1666,    0,  1570,  2136,
  1445,    1, -1296, -1721,  -1132,    9,   982,  1269,
   821,   21,  -615,  -762,   -435,   90,   495,   613,
   485,  284,   186,   287,    594, 1058, -1468};

/*FUNKTIONER TIL TYPEKONVERTERING AF ARRAYS
enten konverter inputtet til double og brug
de af matlab genererede koefficienter eller 
konverter matlab koefficienter til int16. Ved
ikke hvad der tager længest tid.*/
void intToDouble( int16_t *input, double *output, int length )
{
    int i;
 
    for ( i = 0; i < length; i++ ) {
        output[i] = (double)input[i];
    }
}
 
void DoubleToInt( double *input, int16_t *output, int length )
{
    int i;
 
    for ( i = 0; i < length; i++ ) {
        if ( input[i] > 32767.0 ) {
            input[i] = 32767.0;
        } else if ( input[i] < -32768.0 ) {
            input[i] = -32768.0;
        }
        output[i] = (int16_t)input[i];
    }
}

//ISR PROTOER
CY_ISR_PROTO(ISR_DMA_Done);

//
    /* DMA_Chan is used to store the DMA channel handle */ 
uint8 DMA_Chan;

/* DMA_TD array is used to store all of the TDs associated with the channel*/
//Transaction Descriptors "navigerer" data
//2 for ping pong array, hvis t_proc >> t_sample ((ping pong buffer)
//1 for circular array. Bruges som udgangspunkt.
uint8 DMA_TD[1]; 

/* DMA_DISABLE_TD definition not available for PSoC 5LP inside CyDmac.h in PSoC Creator 2.1 SP1.
 * So, manually define the DMA_DISABLE_TD */
#if (CY_PSOC5LP)
	#if !defined(DMA_DISABLE_TD)
	    #define DMA_DISABLE_TD          0xFEu
	#endif
#endif  /* (CY_PSOC5LP) */

//Sample arrays som DMA fylder op

//Hvis differentiel, add dc offset +32768 for int16 for meningsfuld output
//Hvis single ended er der 2,5V DC på + indgangen til ADC - brug derfor uint16_t
static int16 adc_sampleArray1[NO_OF_SAMPLES]={0}; 
//Udkommenter nedenstående for ping pong buffer
//static int16 adc_sampleArray2[NO_OF_SAMPLES]={0};

void Init()
{   //8 bit = 1 byte pr burst (1 byte til memory ad gangen)
    //16 bit = 2 byte pr burst
    DMA_Chan = DMA_1_DmaInitialize(DMA_BYTES_PER_BURST, DMA_REQUEST_PER_BURST, HI16(DMA_SRC_BASE), HI16(DMA_DST_BASE));
		
    /*CyDmaTdAllocate - Allocate TDs */
    
	DMA_TD[0] = CyDmaTdAllocate();
	//DMA_TD[1] = CyDmaTdAllocate(); //Udkommenter for ping pong buffer
    
    /*NO_OF_SAMPLES ad gangen (NO_OF_SAMPLES * 2 byte), 
    inkrementer transaction descriptor, lav interrupt når færdig
    Udkommenter nummer 2 for ping pong buffer*/
    CyDmaTdSetConfiguration(DMA_TD[0],TRANSFER_COUNT, DMA_TD[0],  TD_INC_DST_ADR | DMA_1__TD_TERMOUT_EN);
	//CyDmaTdSetConfiguration(DMA_TD[1], TRANSFER_COUNT, DMA_DISABLE_TD, TD_INC_DST_ADR | DMA_1__TD_TERMOUT_EN);
    
    //Sætter destinationsadressen til sampleArray1, peger på første plads
    CyDmaTdSetAddress(DMA_TD[0], LO16((uint32)ADC_DelSig_1_DEC_SAMP_PTR), LO16((uint32)&adc_sampleArray1[0]));
    //Udkommenter nedenstående for ping pong buffer
	//CyDmaTdSetAddress(DMA_TD[1], LO16((uint32)ADC_DelSig_1_DEC_SAMP_PTR), LO16((uint32)&adc_sampleArray2[0]));
    
    /*Map the TD to the DMA Channel */
	CyDmaChSetInitialTd(DMA_Chan, DMA_TD[0]);
    
    //Enable DMA channel. 
    CyDmaChEnable(DMA_Chan, 1);

	/* Start ADC */
	ADC_DelSig_1_Start();
    
    //Start VREF
    Opamp_1_Start();
    Opamp_2_Start();
   
    //Start DAC
    VDAC8_1_Start();
    
    /* Disable the ADC ISR as it is not required */
    ADC_DelSig_1_IRQ_Disable();

	/* Start ADC conversion */
	ADC_DelSig_1_StartConvert();
	
	/* Start isr connected to DMA nrq signal */
	ISR_DMA_Done_Start();

	/* Enable global interrupt */
	CYGlobalIntEnable; 
    
};


//Når DMA er done med at overføre SAMPLE ARRAYS startes DMA_Done interrupt
CY_ISR(ISR_DMA_Done)
{
    
//Filteret ryddes for gammel data
firFixedInit();


//De indhentede samples fra ADC kopieres til et working array for filtret 
int16_t *filter_workingArray1 = firStoreNewSamples(adc_sampleArray1, NO_OF_SAMPLES);
int16_t filter_outputArray[NO_OF_SAMPLES];

/*Definer flere koefficientarrays og brug dette koefficient array i kald
samme metode med nyt koefficientarray for at lade adc input samples 
gennemløbe flere arrays uden at påvirke hinanden*/
firFixed(coeffs, filter_workingArray1, filter_outputArray, NO_OF_SAMPLES, FILTER_LEN);

//Skift de samples der lige er blevet processeret ud med 
firMoveProcSamples(NO_OF_SAMPLES);
  
//Debug   
//VDAC8_1_SetValue((32768u+adc_sampleArray1[0])>>8); //16 bit offset
//VDAC8_1_SetValue((32768u+ADC_DelSig_1_GetResult16())>>8);

}

int main(void)
{
    Init();
    
    for(;;)
    {
       
       
    }
}

/* [] END OF FILE */

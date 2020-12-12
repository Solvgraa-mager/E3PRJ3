#include "fir_filter1.h"

/*I DETTE TILFÆLDE BRUGES DMA TIL AT FLYTTE DATA OG ALLOKERE.
DER PROCESSERES PÅ PAKKER AF NO_OF_SAMPLES OG IKKE PR. SAMPLE.
DERFOR BENYTTES firStoreNewInputSamples TIL AT GEMME BÅDE 
KOEFFICIENTER OG adc_SampleArray[NO_OF_SAMPLES] I ET ARRAY TIL FILTERET.
*/

//array til at holde både input samples og filter koefficienter
int16_t insamp[ BUFFER_LEN ];

/* FIR init, rydder hele filtrets buffer
kaldes lige inden filter funktionen kaldes 
for at sikre at der ikke bliver filtreret på
noget som måtte ligge i filtret i forvejen*/
void firFixedInit( void )
{
 memset( insamp, 0, sizeof( insamp ) );
}

//tager pakker af ADC data
int16_t *firStoreNewSamples( int16_t *inp, int length )
{
    /*Skubber adc array over i et array for filtret.
    Her er ADC samples i øvre ende af filter_workArray
    koefficienter i nedre ende af filter_workArray*/
    memcpy( &insamp[MAX_FLT_LEN - 1], inp,
            length * sizeof(int16_t) );
    //returnerer adresse som fir-filter funktionen benytter som parameter
    //og derved hvor filtret skal begynde akkumulering
    return &insamp[MAX_FLT_LEN - 1]; 
}

/*alle adc samples fra filter workingarray (insamps øverste pladser)
shiftes "tilbage i tid" med samme antal som det nye antal samples
*/
void firMoveProcSamples( int length )
{
    memmove( &insamp[0], &insamp[length],
            (MAX_FLT_LEN - 1) * sizeof(int16_t) );
}

//FIR filter funktion
void firFixed(int16_t *coeffs, int16_t *input, int16_t *output,
       int length, int filterLength )
{
    int32_t acc;     // accumulator for gange og plus
    int16_t *coeffp; // pointer til filterkoefficienter
    
    //er blevet formateret fra int16
    int16_t *inputp; // pointer til input samples
    int n;
    int k;

    // apply the filter to each input sample
    for ( n = 0; n < length; n++ ) {
        // calculate output n
        coeffp = coeffs;
        inputp = &input[n];
        //akkumulator til at holde summen 
        //af hver input sampl ganget på filter koefficient
        acc = 1 << 14;
        //gange input igennem koefficienter (impulsrespons for digitalt filter)
        //her er shiftet om tidsaksen (delayregisteret er indstillet) inden (funktionen firMoveProcSamples() )
        for ( k = 0; k < filterLength; k++ ) {
            
            /*koefficienter nederst i filter_workingArray, 
            lydinput øverst i filter_workingArray.
            Gange første koeff med nuværende sample
            og gange anden koefficient med sidste sample
            h(k)*x(n-k)*/
            
            //koefficienter fra matlab er formatteret til int
            //for at passe med input samples
            acc += (int32_t)(*coeffp++) * (int32_t)(*inputp--);
        }
        //overflows sikring max +- 2^14 for akkumulator
        if ( acc > 0x3fffffff ) {
            acc = 0x3fffffff;
        } else if ( acc < -0x40000000 ) {
            acc = -0x40000000;
        }
        
        //filter output skaleret fra int32 til uint16_t array
        output[n] = (int16_t)(acc >> 15);
    }
}
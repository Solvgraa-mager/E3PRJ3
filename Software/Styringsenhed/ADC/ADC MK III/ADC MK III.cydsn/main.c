/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
 */
//#include "fft.h"
#include "project.h"
#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
//#include <tgmath.h>
#include "fir_filter1.h"
#define NO_OF_SAMPLES 80 //
#define TRANSFER_COUNT1 NO_OF_SAMPLES1 * 2
//#define TRANSFER_COUNT2 NO_OF_SAMPLES2 * 2
volatile char DMA_Done_Flag = 0;

/* Defines for DMA_1 */
#define DMA_1_BYTES_PER_BURST 2
#define DMA_1_REQUEST_PER_BURST 1
#define DMA_1_SRC_BASE (CYDEV_PERIPH_BASE)
#define DMA_1_DST_BASE (CYDEV_SRAM_BASE)

/* Variable declarations for DMA_1 */
/* Move these variable declarations to the top of the function */

CY_ISR_PROTO(ISR_DMA_Done);

char uartBuffer[256];

static int16_t ADC_Sample[NO_OF_SAMPLES] = { 0 };

//static uint16 FFTresult[n];



//FILTER 1
#define FILTER_LEN 68
static int16_t coeffs[ FILTER_LEN ] =
{86,81,76,69,58,38,9,-34,-92,-166,-254,-356,-466,-579,-690,-789,-869,-922,-940,-916,-847,-729,-565,-356,-110,166,459,757,1047,1315,1547,1733,1862,1928,1928,1862,1733,1547,1315,1047,757,459,166,-110,-356,-565,-729,-847,-916,-940,-922,-869,-789,-690,-579,-466,-356,-254,-166,-92,-34,9,38,58,69,76,81,86};







int
main(void)
{
    
  CyGlobalIntEnable; /* Enable global interrupts. */

  ISR_DMA_Done_StartEx(ISR_DMA_Done);
  Opamp_1_Start();
  UART_1_Start();
  ADC_DelSig_Start();
  ADC_DelSig_StartConvert();


  uint8 DMA_1_Chan;
  uint8 DMA_1_TD[1];

  /* DMA Configuration for DMA_1 */
  DMA_1_Chan = DMA_1_DmaInitialize(DMA_1_BYTES_PER_BURST,
                                   DMA_1_REQUEST_PER_BURST,
                                   HI16(DMA_1_SRC_BASE),
                                   HI16(DMA_1_DST_BASE));
  DMA_1_TD[0] = CyDmaTdAllocate();
  CyDmaTdSetConfiguration(DMA_1_TD[0],
                          1 * NO_OF_SAMPLES,
                          DMA_1_TD[0],
                          DMA_1__TD_TERMOUT_EN | CY_DMA_TD_INC_DST_ADR);
  CyDmaTdSetAddress(DMA_1_TD[0],
                    LO16((uint32)ADC_DelSig_DEC_SAMP_PTR),
                    LO16((uint32)&ADC_Sample[0]));
  CyDmaChSetInitialTd(DMA_1_Chan, DMA_1_TD[0]);
  CyDmaChEnable(DMA_1_Chan, 1);

  UART_1_PutString("Starting...\n");

  for (;;) {
  }
}



CY_ISR(ISR_DMA_Done)
{
  Proc_done_test_Write(1);
//  ADC_DelSig_StopConvert();
//  uint16 binSum1 = 0;
//  uint16 binSum2 = 0;
//  uint16 binSum3 = 0;
//  uint16 binSum4 = 0;

//
//   for (size_t i = 0; i < NO_OF_SAMPLES; i++) {
//      snprintf(uartBuffer, sizeof(uartBuffer), "%d\n", ADC_Sample[i]);
//      UART_1_PutString(uartBuffer);
//    }
////UART_1_PutString("\n\n");
//  int8* ADC_SamplePtr = ADC_Sample;
//  uint16* FFTResultPtr = FFTresult;
//
//  DoFFT(ADC_SamplePtr, FFTResultPtr);

//Filteret ryddes for gammel data
firFixedInit();

//De indhentede samples fra ADC kopieres til et working array for filtret 
int16_t *filter_workingArray1 = firStoreNewSamples(ADC_Sample, NO_OF_SAMPLES);
int16_t filter_outputArray[NO_OF_SAMPLES];

   for (size_t i = 0; i < NO_OF_SAMPLES; i++) {
      snprintf(uartBuffer, sizeof(uartBuffer), "%d,%d\n",ADC_Sample[i], filter_outputArray[i]);
      UART_1_PutString(uartBuffer);
    }

/*Definer flere koefficientarrays og brug dette koefficient array i kald
samme metode med nyt koefficientarray for at lade adc input samples 
gennemløbe flere arrays uden at påvirke hinanden*/
firFixed(coeffs, filter_workingArray1, filter_outputArray, NO_OF_SAMPLES, FILTER_LEN);
           
  for (size_t i = 0; i < NO_OF_SAMPLES; i++) {
    snprintf(uartBuffer,
             sizeof(uartBuffer),
             "%d,%d\n",
             ADC_Sample[i],
             filter_outputArray[i]);
    UART_1_PutString(uartBuffer);
    // VDAC8_1_SetValue(filter_outputArray[i]);
  }
//Skift de samples der lige er blevet processeret ud med 
firMoveProcSamples(NO_OF_SAMPLES);
 
//  binSum1 = FFTResultPtr[7] + FFTResultPtr[8];
//  binSum2 = FFTResultPtr[12] + FFTResultPtr[13];
//  binSum3 = FFTResultPtr[19] + FFTResultPtr[20];
//  binSum4 = FFTResultPtr[24] + FFTResultPtr[25];

;
//  snprintf(uartBuffer,
//           sizeof(uartBuffer),
//           "%d,%d,%d,%d\n",
//           binSum1,
//           binSum2,
//           binSum3,
//           binSum4);
//  UART_1_PutString(uartBuffer);

  Proc_done_test_Write(0);
//  ADC_DelSig_StartConvert();
}

/* [] END OF FILE */

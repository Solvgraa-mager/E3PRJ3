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
#include "fft.h"
#include "project.h"
#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

#define TRANSFER_COUNT1 NO_OF_SAMPLES1 * 2
#define TRANSFER_COUNT2 NO_OF_SAMPLES2 * 2
volatile char DMA_Done_Flag = 0;
/* Defines for DMA_1 */
#define DMA_1_BYTES_PER_BURST 1
#define DMA_1_REQUEST_PER_BURST 1
#define DMA_1_SRC_BASE (CYDEV_PERIPH_BASE)
#define DMA_1_DST_BASE (CYDEV_SRAM_BASE)

/* Variable declarations for DMA_1 */
/* Move these variable declarations to the top of the function */

CY_ISR_PROTO(ISR_UART_rx_handler);
void
handleByteReceived(uint8 byteReceived);

CY_ISR_PROTO(ISR_DMA_Done);

char uartBuffer[256];

static uint8 ADC_Sample[NO_OF_SAMPLES] = { 0 };

static uint16 FFTresult[n];

int
main(void)
{

  CyGlobalIntEnable; /* Enable global interrupts. */

  ISR_DMA_Done_StartEx(ISR_DMA_Done);
  isr_uart_rx_StartEx(ISR_UART_rx_handler);

  UART_1_Start();
  ADC_DelSig_Start();
  ADC_DelSig_StartConvert();
  VDAC8_1_Start();
  VDAC8_2_Start();
  VDAC8_3_Start();
  VDAC8_4_Start();

  uint8 DMA_1_Chan;
  uint8 DMA_1_TD[1];

  /* DMA Configuration for DMA_1 */
  DMA_1_Chan = DMA_1_DmaInitialize(DMA_1_BYTES_PER_BURST,
                                   DMA_1_REQUEST_PER_BURST,
                                   HI16(DMA_1_SRC_BASE),
                                   HI16(DMA_1_DST_BASE));
  DMA_1_TD[0] = CyDmaTdAllocate();
  CyDmaTdSetConfiguration(DMA_1_TD[0],
                          2 * NO_OF_SAMPLES,
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

CY_ISR(ISR_UART_rx_handler)
{
  uint8 bytesToRead = UART_1_GetRxBufferSize();
  while (bytesToRead > 0) {
    uint8 byteReceived = UART_1_ReadRxData();
    UART_1_WriteTxData(byteReceived); // echo back

    handleByteReceived(byteReceived);

    bytesToRead--;
  }
}

void
handleByteReceived(uint8 byteReceived)
{
  switch (byteReceived) {
    case 'q': {
      UART_1_PutString("q pressed! \n");
    } break;
    case 'w': {
      UART_1_PutString("w pressed! \n");
    } break;
    default: {
      // nothing
    } break;
  }
}

CY_ISR(ISR_DMA_Done)
{
  dma_done_test_Write(1);
  ADC_DelSig_StopConvert();
  int binSum1 = 0;
  int binSum2 = 0;
  int binSum3 = 0;
  int binSum4 = 0;
  // for (size_t i = 0; i < NO_OF_SAMPLES; i++) {
  //    snprintf(uartBuffer, sizeof(uartBuffer), "%d: %d\n", i, ADC_Sample[i]);
  //    UART_1_PutString(uartBuffer);
  //  }

  uint8* ADC_SamplePtr = ADC_Sample;
  uint16* FFTResultPtr = FFTresult;

  DoFFT(ADC_SamplePtr, FFTResultPtr);
  binSum1 = 0;
  binSum2 = 0;
  binSum3 = 0;
  binSum4 = 0;

  binSum1 = FFTresult[7] + FFTresult[8];
  binSum2 = FFTresult[12] + FFTresult[13];
  binSum3 = FFTresult[19] + FFTresult[20];
  binSum4 = FFTresult[24] + FFTresult[25];


  VDAC8_1_SetValue(binSum1);
  VDAC8_2_SetValue(binSum2);
  VDAC8_3_SetValue(binSum3);
  VDAC8_4_SetValue(binSum4);

  snprintf(uartBuffer,
           sizeof(uartBuffer),
           "Bin1: %d\nBin2: %d\nBin3: %d\nBin4: %d\n\n",
           binSum1,
           binSum2,
           binSum3,
           binSum4);
  UART_1_PutString(uartBuffer);

  dma_done_test_Write(0);

  ADC_DelSig_StartConvert();
}

/* [] END OF FILE */

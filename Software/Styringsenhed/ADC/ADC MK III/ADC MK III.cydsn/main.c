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
#include "project.h"
#include <complex.h>
#include <stdio.h>
#include <tgmath.h>
#include <stdlib.h>
#include "fft.h"

#define NO_OF_SAMPLES2 64
#define n (NO_OF_SAMPLES / 2)


#define TRANSFER_COUNT1 NO_OF_SAMPLES1 * 2
#define TRANSFER_COUNT2 NO_OF_SAMPLES2 * 2
volatile char DMA_Done_Flag = 0;
/* Defines for DMA_1 */
#define DMA_1_BYTES_PER_BURST 2
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
uint16 ADCToFFT[NO_OF_SAMPLES] = {0};
uint16* fftResult; // FFT Result pointer.
uint16 ADC_Sample[NO_OF_SAMPLES] = { 0 };

int
main(void)
{
  CyGlobalIntEnable; /* Enable global interrupts. */

  ISR_DMA_Done_StartEx(ISR_DMA_Done);
    ADC_DelSig_Start(); 
    ADC_DelSig_StartConvert(); 
  isr_uart_rx_StartEx(ISR_UART_rx_handler);
  UART_1_Start();
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
                           DMA_1__TD_TERMOUT_EN |
                            CY_DMA_TD_INC_DST_ADR);
  CyDmaTdSetAddress(DMA_1_TD[0],
                    LO16((uint32)ADC_DelSig_DEC_SAMP_PTR),
                    LO16((uint32)&ADC_Sample[0]));
  CyDmaChSetInitialTd(DMA_1_Chan, DMA_1_TD[0]);
  CyDmaChEnable(DMA_1_Chan, 1);


  /* Place your initialization/startup code here (e.g. MyInst_Start()) */
  UART_1_PutString("Starting...\n");





  for (;;) {
//    CyDelay(100);     
    /* Place your application code here. */
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
   UART_1_PutString("In ISR DMA DONE\n");
    dma_done_test_Write(1);
// We need a buffer...
    fftResult = DoFFT(ADC_Sample);
    UART_1_PutString("Magnitude resultat\n");
    for (size_t i = 0; i < NO_OF_SAMPLES/2; i++) {
        snprintf(uartBuffer,sizeof(uartBuffer),"%d: %d\n",i,fftResult[i]);
        UART_1_PutString(uartBuffer);
    }
     
       UART_1_PutString("BYE BYE ISR DMA DONE\n");    
        dma_done_test_Write(0);
}


/* [] END OF FILE */

// Adam Høj FFT - baseret på metoden i Handbook of Mathematics //
#include "fft.h"

#define omega_n (cpow(cexp(-2 * M_PI * I / n), l * v))
#define omega_N (cpow(cexp(-2 * M_PI * I / NO_OF_SAMPLES), (k / 2) * v))

uint8
DoFFT(uint8* inputArray, uint16* FFTResultPtr)
{

    
float complex coefficientArray[n] = { 0 };
char uartBuffer[256];
// Hanning 
  for (int i = 0; i < NO_OF_SAMPLES; i++) {
    float hann = 0.5 * (1 - cosf(2 * M_PI * i / NO_OF_SAMPLES));
    inputArray[i] = hann * inputArray[i] - 128u;
  }


// FFT udregning
// Lige koefficienter
for (int l = 0; l < n/4; l++) {
      for (int v = 0; v < n; v++) { // Gennemløb op til n.   hvor n = N/2
        coefficientArray[l*2] += (inputArray[v] + inputArray[n + v]) * omega_n;
    }
    // ULIGE coefficient
      for (int v = 0; v < n; v++) {
        coefficientArray[l*2+1] += (inputArray[v] - inputArray[n + v]) *
                               cpow(cexp(-2 * M_PI * I / NO_OF_SAMPLES), v) *
                               omega_n;
    };
  }

  
  FFTResultPtr[0] = (uint16)(2 * coefficientArray[0])>>4;

// Fyld resultater ind i output pointer
  for (int k = 1; k < n/2; k++) {
    FFTResultPtr[k] = (uint16)cabsf(coefficientArray[k]) >> 4;
    FFTResultPtr[n-k] = (uint16)cabsf(conjf(coefficientArray[k])) >> 4;
     snprintf(uartBuffer, sizeof(uartBuffer), "%d: %d\n", k, FFTResultPtr[k]);
     UART_1_PutString(uartBuffer);
  };
  return 0;
}

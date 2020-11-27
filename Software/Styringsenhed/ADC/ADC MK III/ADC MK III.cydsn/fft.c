// Adam Høj FFT - baseret på metoden i Handbook of Mathematics //
#include "fft.h"

#define omega_n (cpow(cexp(-2 * M_PI * I / n), (k / 2) * v))
#define omega_N (cpow(cexp(-2 * M_PI * I / NO_OF_SAMPLES), (k / 2) * v))
void
DoFFT(uint16 inputArray[])
{
  float complex coefficientArray[NO_OF_SAMPLES] = { 0 };
  int16 a[n] = { 0 };
  int16 b[n] = { 0 };
  int32 mag[n] = { 0 };
  int32 phase[n] = { 0 };

  char uartBuffer[256];
  // Pure aesthetics  - no functional use
  //  UART_1_PutString("FFT started.... \r\n");
  // The real deal

  // HANNING !
  for (int i = 0; i < NO_OF_SAMPLES + 1; i++) {
    float hann = 0.5 * (1 - ccosf(2 * M_PI * i / NO_OF_SAMPLES));
    inputArray[i] = hann * inputArray[i];
  }

//UART_1_PutString("input:\n");
//  for (uint8 i = 0; i < NO_OF_SAMPLES; i++) {
//    snprintf(uartBuffer,
//             sizeof(uartBuffer),
//             "%d\n",
//             inputArray[i]);
//    UART_1_PutString(uartBuffer);
//  };



  // Lige koefficienter

  for (uint8 k = 0; k < NO_OF_SAMPLES; k++) {

    if ((k) % 2 == 0) {
      // modulus tjek
      for (uint8 v = 0; v < n; v++) { // Gennemløb op til n.   hvor n = N/2
        coefficientArray[k] += (inputArray[v] + inputArray[n + v]) * omega_n;
      }
    }
    // ULIGE coefficient
    if ((k) % 2 == 1) {
      for (uint8 v = 0; v < n; v++) {
        coefficientArray[k] += (inputArray[v] - inputArray[n + v]) *
                               cpow(cexp(-2 * M_PI * I / NO_OF_SAMPLES), v) *
                               omega_n;
      };
    };
  }


  a[0] = floor(2 * coefficientArray[0]);
  b[0] = 0;
  mag[0] = floor(cabsf(a[0] + b[0] * I));

  for (uint8 k = 1; k < n; k++) {
    a[k] = floor(2 * crealf(coefficientArray[k]));
    b[k] = floor(-2 * cimagf(coefficientArray[k]));
    mag[k] = cabsf(coefficientArray[k]);
    //        mag[k] = cabsf(a[k]+b[k]*I);
    phase[k] = cargf(coefficientArray[k]);
  };
//  UART_1_PutString("a\t b\t mag\t phase\n");
//  for (uint8 i = 0; i < n; i++) {
//    snprintf(uartBuffer,
//             sizeof(uartBuffer),
//             "%d\t %d\t %ld\t %ld\n",
//             a[i],
//             b[i],
//             mag[i],
//             phase[i]);
//    UART_1_PutString(uartBuffer);
//  };
}

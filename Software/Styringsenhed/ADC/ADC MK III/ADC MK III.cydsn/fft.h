#include "project.h"
#include <complex.h>
#include <stdio.h>
#include <tgmath.h>
#include <stdlib.h>
#include <time.h>
#define NO_OF_SAMPLES 80 //
#define n (NO_OF_SAMPLES / 2)
#define SampleRate 10000
#define FrequencyResolution (SampleRate/n)

#define keyFrequency1 280
#define keyFrequency2 475
#define keyFrequency3 750
#define keyFrequency4 950

#define FreqBin1 (uint8)floor(keyFrequency1/FrequencyResolution)
#define FreqBin2 (uint8)floor(keyFrequency2/FrequencyResolution)
#define FreqBin3 (uint8)floor(keyFrequency3/FrequencyResolution)
#define FreqBin4 (uint8)floor(keyFrequency4/FrequencyResolution)

uint8 DoFFT(int8* inputArray, uint16* FFTResultPtr);
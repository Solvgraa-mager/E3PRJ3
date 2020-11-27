#include "project.h"
#include <complex.h>
#include <stdio.h>
#include <tgmath.h>
#include <stdlib.h>
#include <time.h>
#define NO_OF_SAMPLES 32 // = 2^3 
#define n (NO_OF_SAMPLES / 2)

uint16* DoFFT(uint16 inputArray[]);
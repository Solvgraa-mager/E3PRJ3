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
#include <stdio.h>
#include <string.h>

// maximum number of inputs that can be handled
// in one function call
#define MAX_INPUT_LEN 80
// maximum length of filter than can be handled
#define MAX_FLT_LEN 63
// buffer to hold all of the input samples
#define BUFFER_LEN (MAX_FLT_LEN - 1 + MAX_INPUT_LEN)

//Clear buffer med input array
void firFixedInit( void );

int16_t *firStoreNewSamples(int16_t *input, int size );

//Metode til fixed point (int16) operering. Koefficienter fra matlab skal så i andet format???
void firFixed( int16_t *coeffs, int16 *input, int16 *output,
       int length, int filterLength );

void firMoveProcSamples( int length );


/* [] END OF FILE */

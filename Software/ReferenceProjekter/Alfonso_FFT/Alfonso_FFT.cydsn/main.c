#include <device.h>

#define pi 3.14159

#define NUM_FFT 64

int samples[NUM_FFT] = { 128,    203,   249,   249,  203,   128,   52,6,   6,   52,   127,    203,   249,
	249,   203,    128,    52,    6,   6,52,    127,   203,   249,   249,    203,
    128,   52,   6,    6,    52,    127,203,   249,    249,    203,    128,   52,
	6,    6,    52,   127,   203,    249,  249,    203,    128,   52,   6,   6, 
	52,    127,   203,   249,   249,    203,  128,   52,   6,   6,    52,   127,
	203,    249,   249,128,    203,   249,   249,  203,   128,   52,6,   6,   52,   127,    203,   249,
	249,   203,    128,    52,    6,   6,52,    127,   203,   249,   249,    203,
    128,   52,   6,    6,    52,    127,203,   249,    249,    203,    128,   52,
	6,    6,    52,   127,   203,    249,  249,    203,    128,   52,   6,   6, 
	52,    127,   203,   249,   249,    203,  128,   52,   6,   6,    52,   127,
	203,    249,   249};	/* Array to hold input samples */
	
int revsamples[NUM_FFT];

int16 real0[NUM_FFT];		/* Array to hold the real value of samples */
int16 img0[NUM_FFT];			/* Array to hold the img value of samples */

int16 real1[NUM_FFT];		/* Array to hold the real value of samples */
int16 img1[NUM_FFT];			/* Array to hold the img value of samples */

int16 twiddlereal[NUM_FFT/2];	/* Array to hold the real value of twiddle factor */
int16 twiddleimg[NUM_FFT/2];	/* Array to hold the img value of twiddle factor */

int16 interreal[NUM_FFT/2];	/* Array to hold the real product of intermediate multiplication */
int16 interimg[NUM_FFT/2];		/* Array to hold the img product of intermediate multiplication */

float x;
float x2;
float x4;
float x6;
float product;

void main()
{
	uint8 i, j; 
	uint8 revi;
	uint8 localman, localcounter;
	uint8 array0[4] = {0, 16, 32, 48};
	uint8 array[8] = {0, 8, 16, 24, 32, 40, 48, 56};
	uint8 array1[16] = {0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60};
	uint8 array2[32] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32,
						34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62};
	
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
	
	/* Calculate the twiddle factors */
	for(i=0; i< (NUM_FFT/2); i++)
	{
//		x = (2 * pi * i / 64);
//		x2 = x*x;
//		x4 = x2*x2;
//		x6 = x4*x2;
//		product = (1 - (x2/2) + (x4/24) - (x6/720))* 256;
//		twiddlereal[i] = (int16) product ;
//		product = (x*(1 - (x2/6) + (x4/120) - (x6/5040)))*(-256);
//		twiddleimg[i] = (int16) product ;
		product = cos(2 * pi * i / NUM_FFT);
		twiddlereal[i] = (int16) (product *256);
		product = sin(2 * pi * i / NUM_FFT);
		twiddleimg[i] = (int16)(product *(-256));
	}
	
    /* First phase of FFT is arranging the input samples in bit reversed format */
	for(i=0; i< NUM_FFT; i++)
	{
		revi = 0;
		
		localman = i;
		localman = (localman << 6) & (0x40);
		revi = revi | localman;
		
		localman = i;
		localman = (localman << 4) & (0x20);
		revi = revi | localman;
		
		localman = i;
		localman = (localman << 2) & (0x10);
		revi = revi | localman;
		
		localman = i;
		localman = (localman << 0) & (0x08);
		revi = revi | localman;
		
		localman = i;
		localman = (localman >> 2) & (0x04);
		revi = revi | localman;
		
		localman = i;
		localman = (localman >> 4) & (0x02);
		revi = revi | localman;

		localman = i;
		localman = (localman >> 6) & (0x01);
		revi = revi | localman;
		
		revsamples[i] = samples[revi];
	}
	
	for(;;)
	{
	
	/* First stage of FFT radix 2 implementation */
	Pin_Write(1);
	for(i=0; i< NUM_FFT; )
	{
		real0[i] = revsamples[i] + revsamples[i+1];
		real0[i+1] = revsamples[i] - revsamples[i+1];
		i = i+2;
	}
	
	/* Second stage of FFT radix 2 implementation */
	for(i=0; i< NUM_FFT; )
	{
		real1[i] = real0[i] + real0[i+2];
		img1[i] = img0[i] + img0[i+2];
		
		real1[i+1] = real0[i+1] + ((real0[i+3] * twiddlereal[32])/256);
		img1[i+1] = (real0[i+3] * twiddleimg[32])/256;
		
		real1[i+2] = real0[i] - real0[i+2];
		img1[i+2] = img0[i] - img0[i+2];
		
		real1[i+3] = real0[i+1] -(( real0[i+3] * twiddlereal[32])/256);
		img1[i+3] = (-1) * real0[i+3] * twiddleimg[32] / 256;
		
		i = i + 4;
	}
	
	/* Third stage of FFT radix 2 implementation */
	for(i=0; i< NUM_FFT; )
	{
		
		for(j = 0; j< 4; j++)
		{
			interreal[j] = ((real1[i + j + 4] * twiddlereal[array0[j]]) - (img1[i + j + 4] * twiddleimg[array0[j]]))/256;
			interimg[j] = ((real1[i + j + 4] * twiddleimg[array0[j]]) + (img1[i + j + 4] * twiddlereal[array0[j]]))/256;
			
		}
		
		
		for(localcounter = 0; localcounter<4; localcounter++)
		{
			real0[i + localcounter] = real1[i + localcounter] + interreal[localcounter];
			img0[i + localcounter] = img1[i + localcounter] + interimg[localcounter];
		}
		 
		for(localcounter = 4; localcounter<8; localcounter++)
		{
			real0[i + localcounter] = real1[i + localcounter - 4] - interreal[localcounter % 4];
			img0[i + localcounter] = img1[i + localcounter - 4] - interimg[localcounter % 4];
		}
		i = i+8;
	}
	
	/* Fourth stage of FFT radix 2 implementation */
	for(i=0; i< NUM_FFT;  )
	{
		
		for(j = 0; j< 8; j++)
		{
			interreal[j] = ((real0[i + j + 8] * twiddlereal[array[j]]) - (img0[i + j + 8] * twiddleimg[array[j]]))/256;
			interimg[j] = ((real0[i + j + 8] * twiddleimg[array[j]]) + (img0[i + j + 8] * twiddlereal[array[j]]))/256;
			
		}
		
		
		for(localcounter = 0; localcounter<8; localcounter++)
		{
			real1[i + localcounter] = real0[i + localcounter] + interreal[localcounter];
			img1[i + localcounter] = img0[i + localcounter] + interimg[localcounter];
		}
		 
		for(localcounter = 8; localcounter<16; localcounter++)
		{
			real1[i + localcounter] = real0[i + localcounter - 8] - interreal[localcounter % 8];
			img1[i + localcounter] = img0[i + localcounter - 8] - interimg[localcounter % 8];
		}
		i = i+16;
	}
		
	/* Fifth stage of Radix 2 FFT implementation */
	for(i=0; i< NUM_FFT; )
	{
		for(j = 0; j< 16; j++)
		{
			interreal[j] = ((real1[i + j + 16] * twiddlereal[array1[j]]) - (img1[i + j + 16] * twiddleimg[array1[j]]))/256;
			interimg[j] = ((real1[i + j + 16] * twiddleimg[array1[j]]) + (img1[i + j + 16] * twiddlereal[array1[j]]))/256;
			
		}
		
		
		for(localcounter = 0; localcounter< 16; localcounter++)
		{
			real0[i + localcounter] = real1[i + localcounter] + interreal[localcounter];
			img0[i + localcounter] = img1[i + localcounter] + interimg[localcounter];
		}
		
		for(localcounter = 16; localcounter< 32; localcounter++)
		{
			real0[i + localcounter] = real1[i + localcounter - 16] - interreal[localcounter % 16];
			img0[i + localcounter] = img1[i + localcounter - 16] - interimg[localcounter % 16];
		}
		i = i+32;
	}
	
	/* Sixth stage of FFT Radix 2, 64 point FFT */
	for(i=0; i< NUM_FFT; )
	{
	for(j = 0; j< 32; j++)
	{
		interreal[j] = ((real0[i+ j + 32] * twiddlereal[array2[j]]) - (img0[i+j + 32] * twiddleimg[array2[j]]))/ 256;
		interimg[j] = ((real0[i+ j + 32] * twiddleimg[array2[j]]) + (img0[i+j + 32] * twiddlereal[array2[j]]))/256;
				
	}
		
	for(localcounter = 0; localcounter< 32; localcounter++)
	{
		real1[i + localcounter] = real0[i+localcounter] + interreal[localcounter];
		img1[i + localcounter] = img0[i+localcounter] + interimg[localcounter];
	}
	
	for(localcounter = 32; localcounter< 64; localcounter++)
	{
		real1[i + localcounter] = real0[i + localcounter - 32] - interreal[localcounter % 32];
		img1[i + localcounter] = img0[i + localcounter - 32] - interimg[localcounter % 32];
	}
		i = i+64;
	}
	/* Sveneth stage of the Radix 2 128 point FFT */
		for(j = 0; j< 64; j++)
	{
		interreal[j] = ((real1[ j + 64] * twiddlereal[j]) - (img1[j + 64] * twiddleimg[j]))/ 256;
		interimg[j] = ((real1[ j + 64] * twiddleimg[j]) + (img1[j + 64] * twiddlereal[j]))/256;
				
	}
		
	for(localcounter = 0; localcounter< 64; localcounter++)
	{
		real0[localcounter] = real1[localcounter] + interreal[localcounter];
		img0[localcounter] = img1[localcounter] + interimg[localcounter];
	}
	
	for(localcounter = 64; localcounter< 128; localcounter++)
	{
		real0[localcounter] = real1[localcounter - 64] - interreal[localcounter % 64];
		img0[localcounter] = img1[localcounter - 64] - interimg[localcounter % 64];
	}
	
	Pin_Write(0);
	
	CyDelay(10);
	}
	
}

/* [] END OF FILE */
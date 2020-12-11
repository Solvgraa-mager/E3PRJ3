#include "Header.h"

using namespace std;

     char C1[] = {'-','7','7','|','-','4','5', '\0' }; 
	// const char C1[] = {'7','|', '-','4','5', '\0' };
	// const char C1[] = { '-','1','0','0','|', '-','7','0', '\0' };
    // const char C1[] = { '1','0','0','|','1','0', '\0' };
	// const char C1[] = { '0','|','0', '\0' };

int main()
{
	Class_Motor motor;
	motor.setDirSpeed(C1);
	return 0;
}


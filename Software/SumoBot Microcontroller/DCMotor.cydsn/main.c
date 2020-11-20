#include "project.h"
#include "stdio.h"
#include "stdbool.h"

#define STR_LENGTH 64     // Stringlength max // Needs more info.. ?
char str[STR_LENGTH + 1]; // String for sprintf outputs.

void do_motor_forward();
void do_motor_reverse();

char8 Ch;              // Selector Char
uint8 PWMMod;          // PWM enable flag
uint8 PWMReset;        // PWM Reset flag
uint8 PWMInfoF;        // PWM Reset flag
uint8 PWMModDisabler;  // PWM disable flag
uint8 PWMModInc;       // PWM disable flag
uint8 PWMModDec;       // PWM disable flag
uint8 PWMCompareCount; // PWM Duty cycle var
uint8 PWMPeriod;       // PWM Period var
uint16 clkDivideBase; // Get initial division
uint16 clkDivideAmount; // New division

// Ease of print();
void
print(char* str)
{
  UART_PutString(str);
  UART_PutString("\n\n");
  UART_PutString("> ");
}
// RX interrupt service routine
// Not in use at the moment ... But why?
CY_ISR(RxIsr) {}

// Initialize hardware and components - start from scratch
/* Inspireret af : foobar.com  */
void
init_hardware(void)
{
  UART_ClearRxBuffer();      // Clear UART RX buffer  ---
  UART_ClearTxBuffer();      // Clear UART TX buffer  ---
  usr_rx_isr_ClearPending(); // Clear pending interrupts - start from scratch
  usr_rx_isr_StartEx(RxIsr); // Set RxISR as ISR vector
  UART_Start();              // Start the UART component
  PWM_1_Start();             // Start the PWM 1 components

  // Setting flags
  PWMMod = false;
  PWMModDisabler = false;
  PWMReset = false;
  PWMInfoF = false;
  PWMModInc = false;
  PWMModDec = false;
  // Setting PWM variables
  PWMPeriod = PWM_1_ReadPeriod();
  PWMCompareCount = PWMPeriod / 2;
  PWM_1_WriteCompare(PWMCompareCount);
  clkDivideBase = clock_1_GetDividerRegister()+1;

  CyGlobalIntEnable; /* Enable global interrupts. */
}

void
splash(void)
{
  sprintf(str, "Program started at (%s %s)\n", __DATE__, __TIME__);
  print(str);
}
void
PWMInfo(void)
{
  sprintf(str,
          "PWM period is :      (%d)\nPWM duty cycle is: [%d]\n",
          PWMPeriod,
          PWMPeriod-PWMCompareCount);
  print(str);
}

void
prompt(void)
{
  print("> ");
}

void
clkDivide(uint16 clkDiv)
{
  clkDivideAmount = clkDivideBase*clkDiv-1;
  clock_1_SetDivider(clkDivideAmount);
  snprintf(str, STR_LENGTH, "Clock division is /%d", clkDiv);
  print(str);
}



int
main(void)
{

  init_hardware(); // Start components
  splash();        // Splash screen
  PWMInfo();       // Splash screen

  for (;;) {

    /* Switch case selector */

    Ch = UART_GetChar();
    /* Set flags based on UART command */
    switch (Ch) {
      case 0:
        /* No new data was recieved */
        break;
      case '1':
        clkDivide(1);
        break;
      case '2':
        clkDivide(2);
        break;
      case '3':
        clkDivide(4);
        break;
      case '4':
        clkDivide(8);
        break; 
      case '5':
        clkDivide(16);
        break;
          case '6':
        clkDivide(64);
        break;    
        // Enabler
      case 'O':        // Uppercase input
      case 'o':        // Lowercase input
        PWMMod = true; // Raise flag
        break;         // Leave switchcase

        // Disabler
      case 'X':                // Uppercase input
      case 'x':                // Lowercase input
        PWMModDisabler = true; // Raise flag
        break;

        // Info display
      case 'i':          // Uppercase input
        PWMInfoF = true; // Raise flag
        break;           // Leave switchcase

        // Increment Compare
      case '+':           // 
        PWMModInc = true; // Raise flag
        break;            // Leave switchcase

        // Decrement Compare
      case '-':           // 
        PWMModDec = true; // Raise flag
        break;            // Leave switchcase

        // Reset PWM
      case 'R':          // Uppercase input
      case 'r':          // Lowercase input
        PWMReset = true; // Raise flag
        break;           // Leave switchcase

      case 'f':
        do_motor_forward();
        break;
        
      case 't':
        do_motor_reverse();
        break;
      default:
        break;
    }

    /* Methods for toggling PWM mode */

    /* Enabler */
    if (PWMMod) {
      PWM_1_Wakeup();    // Enable the pwm
      print("[PWM on]"); // Print output msg.
      PWMMod = false;    // Disable flag
      /* Disabler */
    } else if (PWMModDisabler) {
      /* code */
      PWM_1_Sleep();          // Disable PWM
      print("[PWM off]");     // Print status msg.
      PWMModDisabler = false; // Disable flag

    } else if (PWMReset) {
      /* code */
      PWMCompareCount = PWMPeriod / 2;
      PWM_1_WriteCompare(PWMCompareCount);
      print("[PWM has been reset]"); // Print status msg.
      PWMInfo();
      PWMReset = false; // Disable flag
    } else if (PWMInfoF) {
      /* code */
      PWMInfo();
      PWMInfoF = false; // Disable flag

    } else if (PWMModInc) {
      if (PWMCompareCount < PWMPeriod) {
        PWMCompareCount++;
      } else {
        PWMCompareCount = PWMPeriod;
      }
      PWM_1_WriteCompare(PWMCompareCount);
      sprintf(str,
              "Compare:             [incremented]\nPWM duty cycle is : [%d]",
              PWMPeriod-PWMCompareCount);
      print(str);        // Print status msg.
      PWMModInc = false; // Disable flag
    } else if (PWMModDec) {
      if (0 < PWMCompareCount) { // Above zero?
        PWMCompareCount--;       // Decrement it !
      } else {                   // ELse ????
        PWMCompareCount = 0;     // Stay at one
      }
      PWM_1_WriteCompare(PWMCompareCount);
      sprintf(str,
              "Compare:             [decremented]\nPWM duty cycle is : [%d]",
              PWMPeriod-PWMCompareCount);
      print(str);        // Print status msg.
      PWMModDec = false; // Disable flag
    }
  }
}

void do_motor_forward()
{
    Motor_1_Write(1);
    Motor_2_Write(0);
}

void do_motor_reverse()
{
    Motor_1_Write(0);
    Motor_2_Write(1);
}
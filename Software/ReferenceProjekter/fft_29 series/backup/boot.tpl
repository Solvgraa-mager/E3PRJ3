;@Id: boot.tpl#53 @
;=============================================================================
;  FILENAME:   boot.asm
;  VERSION:    4.15
;  DATE:       2 August 2004
;
;  DESCRIPTION:
;  M8C Boot Code for CY8C27xxx microcontroller family.
;
;  Copyright (C) Cypress MicroSystems 2000-2004. All rights reserved.
;
; NOTES:
; PSoC Designer's Device Editor uses a template file, BOOT.TPL, located in
; the project's root directory to create BOOT.ASM. Any changes made to
; BOOT.ASM will be  overwritten every time the project is generated; therfore
; changes should be made to BOOT.TPL not BOOT.ASM. Care must be taken when
; modifying BOOT.TPL so that replacement strings (such as @PROJECT_NAME)
; are not accidentally modified.
;
;=============================================================================

include ".\lib\GlobalParams.inc"
include "m8c.inc"
include "m8ssc.inc"
include "memory.inc"

;--------------------------------------
; Export Declarations
;--------------------------------------

export __Start
export __bss_start
export __data_start
export __idata_start
export __func_lit_start
export __text_start
export  _bGetPowerSetting
export   bGetPowerSetting


;--------------------------------------
; Optimization flags
;--------------------------------------
;
; To change the value of these flags, modify the file boot.tpl, not
; boot.asm. See the notes in the banner comment at the beginning of
; this file.

; Optimization for Assembly language (only) projects and C-language projects
; that do not depend on the C compiler to initialize the values of RAM variables.
;   Set to 1: Support for C Run-time Environment initialization
;   Set to 0: Support for C not included. Faster start up, smaller code space.
;
C_LANGUAGE_SUPPORT:              equ 1


; The following equate is required for proper operation. Reseting its value
; is discouraged.  WAIT_FOR_32K is effective only if the crystal oscillator is
; selected.  If the designer chooses to not wait then stabilization of the ECO
; and PLL_Lock must take place within user code. See the family data sheet for
; the requirements of starting the ECO and PLL lock mode.
;
;   Set to 1: Wait for XTAL (& PLL if selected) to stabilize before
;                invoking main
;   Set to 0: Boot code does not wait; clock may not have stabilized by
;               the time code in main starts executing.
;
WAIT_FOR_32K:                    equ 1


; For historical reasons, by default the boot code uses an lcall instruction
; to invoke the user's _main code. If _main executes a return instruction,
; boot provides an infinite loop. By changing the following equate from zero
; to 1, boot's lcall will be replaced by a ljmp instruction, saving two
; bytes on the stack which are otherwise required for the return address. If
; this option is enabled, _main must not return. (Beginning with the 4.2
; release, the C compiler automatically places an infinite loop at the end
; of main, rather than a return instruction.)
;
ENABLE_LJMP_TO_MAIN:             equ 0


;-----------------------------------------------------------------------------
; Interrupt Vector Table
;-----------------------------------------------------------------------------
;
; Interrupt vector table entries are 4 bytes long.  Each one contains
; a jump instruction to an ISR (Interrupt Service Routine), although
; very short ISRs could be encoded within the table itself. Normally,
; vector jump targets are modified automatically according to the user
; modules selected. This occurs when the 'Generate Application' opera-
; tion is run causing PSoC Designer to create boot.asm and the other
; configuration files. If you need to hard code a vector, update the
; file boot.tpl, not boot.asm. See the banner comment at the beginning
; of this file.
;-----------------------------------------------------------------------------

    AREA TOP (ROM, ABS, CON)

    org   0                        ;Reset Interrupt Vector
    jmp   __Start                  ;First instruction executed following a Reset

    org   04h                      ;Supply Monitor Interrupt Vector
    halt                           ;Stop execution if power falls too low

    org   08h                      ;Analog Column 0 Interrupt Vector
    `@INTERRUPT_2`
    reti

    org   0Ch                      ;Analog Column 1 Interrupt Vector
    `@INTERRUPT_3`
    reti

    org   10h                      ;Analog Column 2 Interrupt Vector
    `@INTERRUPT_4`
    reti

    org   14h                      ;Analog Column 3 Interrupt Vector
    `@INTERRUPT_5`
    reti

    org   18h                      ;VC3 Interrupt Vector
    `@INTERRUPT_6`
    reti

    org   1Ch                      ;GPIO Interrupt Vector
    `@INTERRUPT_7`
    reti

    org   20h                      ;PSoC Block DBB00 Interrupt Vector
    `@INTERRUPT_8`
    reti

    org   24h                      ;PSoC Block DBB01 Interrupt Vector
    `@INTERRUPT_9`
    reti

    org   28h                      ;PSoC Block DCB02 Interrupt Vector
    `@INTERRUPT_10`
    reti

    org   2Ch                      ;PSoC Block DCB03 Interrupt Vector
    `@INTERRUPT_11`
    reti

    org   30h                      ;PSoC Block DBB10 Interrupt Vector
    `@INTERRUPT_12`
    reti

    org   34h                      ;PSoC Block DBB11 Interrupt Vector
    `@INTERRUPT_13`
    reti

    org   38h                      ;PSoC Block DCB12 Interrupt Vector
    `@INTERRUPT_14`
    reti

    org   3Ch                      ;PSoC Block DCB13 Interrupt Vector
    `@INTERRUPT_15`
    reti

    org   60h                      ;PSoC I2C Interrupt Vector
    `@INTERRUPT_24`
    reti

    org   64h                      ;Sleep Timer Interrupt Vector
    `@INTERRUPT_25`
    reti

;-----------------------------------------------------------------------------
;  Start of Execution.
;-----------------------------------------------------------------------------
;  The Supervisory ROM SWBootReset function has already completed the
;  calibrate1 process, loading trim values for 5 volt operation.
;
    org 68h
__Start:

    ; initialize SMP values for voltage stabilization, if required,
    ; leaving power-on reset (POR) level at the default (low) level, at
    ; least for now. 
    ;
    M8C_SetBank1
    mov   reg[VLT_CR], SWITCH_MODE_PUMP_JUST | LVD_TBEN_JUST | TRIP_VOLTAGE_JUST
    M8C_SetBank0

IF ( WATCHDOG_ENABLE )             ; WDT selected in Global Params
    M8C_EnableWatchDog
ENDIF

IF ( SELECT_32K )
    or   reg[CPU_SCR1],  CPU_SCR1_ECO_ALLOWED  ; ECO will be used in this project
ELSE
    and  reg[CPU_SCR1], ~CPU_SCR1_ECO_ALLOWED  ; Prevent ECO from being enabled
ENDIF

    ;------------------
    ; Set up the stack
    ;------------------
    mov   A, __ramareas_end        ; Set top of stack to end of used RAM
    swap  SP, A                    ; This is only temporary if going to LMM

    ;-----------------------------------------------
    ; Set Power-related Trim & the AGND Bypass bit.
    ;-----------------------------------------------

IF ( SUPPLY_VOLTAGE )         ; 1 means 5.0V
 IF ( AGND_BYPASS )
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ; The 5V trim has already been set, but we need to update the AGNDBYP
    ; bit in the write-only BDG_TR register. Recalculate the register
    ; value using the proper trim values.
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    M8SSC_SetTableVoltageTrim 1, SSCTBL1_TRIM_BGR_5V, AGND_BYPASS_JUST
 ENDIF
ELSE    ; 3.3 V Operation, not 5.0V
    M8SSC_SetTableTrims  1, SSCTBL1_TRIM_IMO_3V_24MHZ, SSCTBL1_TRIM_BGR_3V, AGND_BYPASS_JUST
ENDIF ;(SUPPLY_VOLTAGE)

    mov  [bSSC_KEY1],  0           ; Lock out Flash and Supervisiory operations
    mov  [bSSC_KEYSP], 0

    ;---------------------------------------
    ; Initialize Crystal Oscillator and PLL
    ;---------------------------------------

IF ( SELECT_32K & WAIT_FOR_32K )
    ; If the user has requested the External Crystal Oscillator (ECO) then turn it
    ; on and wait for it to stabilize and the system to switch over to it. The PLL
    ; is left off. Set the SleepTimer period is set to 1 sec to time the wait for
    ; the ECO to stabilize.
    ;
    M8C_SetBank1
    mov   reg[OSC_CR0], (SELECT_32K_JUST | OSC_CR0_SLEEP_1Hz | OSC_CR0_CPU_12MHz)
    M8C_SetBank0
    M8C_ClearWDTAndSleep                  ; Reset the sleep timer to get a full second
    or    reg[INT_MSK0], INT_MSK0_SLEEP   ; Enable latching of SleepTimer interrupt
    mov   reg[INT_VC],   0                ; Clear all pending interrupts
.WaitFor1s:
    tst   reg[INT_CLR0], INT_MSK0_SLEEP   ; Test the SleepTimer Interrupt Status
    jz   .WaitFor1s                       ; Interrupt will latch but will not dispatch
                                          ;   since interrupts are not globally enabled
ELSE ; !( SELECT_32K & WAIT_FOR_32K )
    ; Either no ECO, or waiting for stable clock is to be done in main
    M8C_SetBank1
    mov   reg[OSC_CR0], (SELECT_32K_JUST | PLL_MODE_JUST | SLEEP_TIMER_JUST | OSC_CR0_CPU_12MHz)
    M8C_SetBank0
    M8C_ClearWDTAndSleep           ; Reset the watch dog

ENDIF ;( SELECT_32K & WAIT_FOR_32K )

IF ( PLL_MODE )
    ; Crystal is now fully operational (assuming WAIT_FOR_32K was enabled).
    ; Now start up PLL if selected, and wait 16 msec for it to stabilize.
    ;
    M8C_SetBank1
    mov   reg[OSC_CR0], (SELECT_32K_JUST | PLL_MODE_JUST | OSC_CR0_SLEEP_64Hz | OSC_CR0_CPU_3MHz)
    M8C_SetBank0
    M8C_ClearWDTAndSleep                  ; Reset the sleep timer to get full period
    mov   reg[INT_VC], 0                  ; Clear all pending interrupts

.WaitFor16ms:
    tst   reg[INT_CLR0],INT_MSK0_SLEEP    ; Test the SleepTimer Interrupt Status
    jz   .WaitFor16ms
    M8C_SetBank1                          ; continue boot at CPU Speed of SYSCLK/2
    mov   reg[OSC_CR0], (SELECT_32K_JUST | PLL_MODE_JUST | OSC_CR0_SLEEP_64Hz | OSC_CR0_CPU_12MHz)
    M8C_SetBank0

IF      ( WAIT_FOR_32K )
ELSE ; !( WAIT_FOR_32K )
    ; Option settings (PLL-Yes, ECO-No) are incompatible - force a syntax error
    ERROR_PSoC Disabling WAIT_FOR_32K requires that the PLL_Lock must be enabled in user code.
ENDIF ;(WAIT_FOR_32K)
ENDIF ;(PLL_MODE)

    ;------------------------
    ; Close CT leakage path.
    ;------------------------
    mov   reg[ACB00CR0], 05h
    mov   reg[ACB01CR0], 05h
    mov   reg[ACB02CR0], 05h
    mov   reg[ACB03CR0], 05h

    ;-------------------------
    ; Load Base Configuration
    ;-------------------------
    ; Load global parameter settings and load the user modules in the
    ; base configuration. Exceptions: (1) Leave CPU Speed fast as possible
    ; to minimize start up time; (2) We may still need to play with the
    ; Sleep Timer.
    ;
    lcall LoadConfigInit

    ;-----------------------------------
    ; Initialize C Run-Time Environment
    ;-----------------------------------
IF ( C_LANGUAGE_SUPPORT )
    mov  A,0                           ; clear the 'bss' segment to zero
    mov  [__r0],<__bss_start
BssLoop:
    cmp  [__r0],<__bss_end
    jz   BssDone
    mvi  [__r0],A
    jmp  BssLoop
BssDone:
    mov  A,>__idata_start              ; copy idata to data segment
    mov  X,<__idata_start
    mov  [__r0],<__data_start
IDataLoop:
    cmp  [__r0],<__data_end
    jz   C_RTE_Done
    push A
    romx
    mvi  [__r0],A
    pop  A
    inc  X
    adc  A,0
    jmp  IDataLoop

C_RTE_Done:

ENDIF ; C_LANGUAGE_SUPPORT

    ;-------------------------------
    ; Voltage Stabilization for SMP
    ;-------------------------------

IF ( SUPPLY_VOLTAGE )                  ; 1 Means 5 Volts
IF ( SWITCH_MODE_PUMP ^ 1 )            ; SMP is operational
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ; When using the SMP at 5V, we must wait for Vdd to slew from 3.1V to
    ; 5V before enabling the Precision Power-On Reset (PPOR).
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    or   reg[INT_MSK0],INT_MSK0_SLEEP
    M8C_SetBank1
    and   reg[OSC_CR0], ~OSC_CR0_SLEEP
    or    reg[OSC_CR0],  OSC_CR0_SLEEP_512Hz
    M8C_SetBank0
    M8C_ClearWDTAndSleep                   ; Restart the sleep timer
    mov   reg[INT_VC], 0                   ; Clear all pending interrupts
.WaitFor2ms:
    tst   reg[INT_CLR0], INT_MSK0_SLEEP    ; Test the SleepTimer Interrupt Status
    jz   .WaitFor2ms                       ; Branch fails when 2 msec has passed
ENDIF ; ( SWITCH_MODE_PUMP ^ 1 )
ENDIF ; ( SUPPLY_VOLTAGE )

    ;-------------------------------
    ; Set Power-On Reset (POR) Level
    ;-------------------------------
    M8C_SetBank1

IF ( SUPPLY_VOLTAGE )                       ; 1 Means 5 Volts
 IF ( CPU_CLOCK_JUST ^ OSC_CR0_CPU_24MHz )  ;    Also 24MHz?
                                            ;       no, set 4.5V POR in user code, if desired
 ELSE ; 24HMz                               ;
    or    reg[VLT_CR],  VLT_CR_POR_HIGH     ;      yes, highest POR trip point required
 ENDIF ; OSC_CRO_CPU_24MHz
ENDIF ; 5V

    M8C_SetBank0

    ;----------------------------
    ; Wrap up and invoke "main"
    ;----------------------------

    ; Disable the Sleep interrupt that was used for timing above.  In fact,
    ; no interrupts should be enabled now, so may as well clear the register.
    ;
    mov  reg[INT_MSK0],0

    ; Everything has started OK. Now select requested CPU & sleep frequency.
    ;
    M8C_SetBank1
    mov  reg[OSC_CR0],(SELECT_32K_JUST | PLL_MODE_JUST | SLEEP_TIMER_JUST | CPU_CLOCK_JUST)
    M8C_SetBank0

    ; Global Interrupt are NOT enabled, this should be done in main().
    ; LVD is set but will not occur unless Global Interrupts are enabled.
    ; Global Interrupts should be enabled as soon as possible in main().
    ;
    mov  reg[INT_VC],0             ; Clear any pending interrupts which may
                                   ; have been set during the boot process.
IF ENABLE_LJMP_TO_MAIN
    ljmp  _main                    ; goto main (no return)
ELSE
    lcall _main                    ; call main
.Exit:
    jmp  .Exit                     ; Wait here after return till power-off or reset
ENDIF

    ;---------------------------------
    ; Library Access to Global Parms
    ;---------------------------------
    ;
 bGetPowerSetting:
_bGetPowerSetting:
    ; Synthesize the "power setting" value used by chips with SlowIMO mode.
    ; Returns value of POWER_SETTING in the A register.
    ; No inputs. No Side Effects.
    ;
IF ( SUPPLY_VOLTAGE )            ; 1 means 5.0V
    mov   A, POWER_SET_5V0_24MHZ   ; Supply & Internal Main Oscillator speed
ELSE        
    mov   A, POWER_SET_3V3_24MHZ   ; Supply & Internal Main Oscillator speed
ENDIF
    ret

    ;---------------------------------
    ; Order Critical RAM & ROM AREAs
    ;---------------------------------
    ;  'TOP' is all that has been defined so far...

    ;  ROM AREAs for C CONST, static & global items
    ;
    AREA lit               (ROM, REL, CON)   ; 'const' definitions
    AREA idata             (ROM, REL, CON)   ; Constants for initializing RAM
__idata_start:

    AREA func_lit          (ROM, REL, CON)   ; Function Pointers
__func_lit_start:

    AREA psoc_config       (ROM, REL, CON)   ; Configuration Load & Unload
    AREA UserModules       (ROM, REL, CON)   ; User Module APIs

    ; CODE segment for general use
    ;
    AREA text (ROM, REL, CON)
__text_start:

    ; RAM area usage
    ;
    AREA data              (RAM, REL, CON)   ; initialized RAM
__data_start:

    AREA virtual_registers (RAM, REL, CON)   ; Temp vars of C compiler
    AREA InterruptRAM      (RAM, REL, CON)   ; Interrupts, on Page 0
    AREA bss               (RAM, REL, CON)   ; general use
__bss_start:

; end of file boot.asm

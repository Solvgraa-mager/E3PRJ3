/*******************************************************************************
* File Name: FFT_Flag.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_FFT_Flag_H) /* Pins FFT_Flag_H */
#define CY_PINS_FFT_Flag_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "FFT_Flag_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 FFT_Flag__PORT == 15 && ((FFT_Flag__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    FFT_Flag_Write(uint8 value);
void    FFT_Flag_SetDriveMode(uint8 mode);
uint8   FFT_Flag_ReadDataReg(void);
uint8   FFT_Flag_Read(void);
void    FFT_Flag_SetInterruptMode(uint16 position, uint16 mode);
uint8   FFT_Flag_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the FFT_Flag_SetDriveMode() function.
     *  @{
     */
        #define FFT_Flag_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define FFT_Flag_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define FFT_Flag_DM_RES_UP          PIN_DM_RES_UP
        #define FFT_Flag_DM_RES_DWN         PIN_DM_RES_DWN
        #define FFT_Flag_DM_OD_LO           PIN_DM_OD_LO
        #define FFT_Flag_DM_OD_HI           PIN_DM_OD_HI
        #define FFT_Flag_DM_STRONG          PIN_DM_STRONG
        #define FFT_Flag_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define FFT_Flag_MASK               FFT_Flag__MASK
#define FFT_Flag_SHIFT              FFT_Flag__SHIFT
#define FFT_Flag_WIDTH              1u

/* Interrupt constants */
#if defined(FFT_Flag__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in FFT_Flag_SetInterruptMode() function.
     *  @{
     */
        #define FFT_Flag_INTR_NONE      (uint16)(0x0000u)
        #define FFT_Flag_INTR_RISING    (uint16)(0x0001u)
        #define FFT_Flag_INTR_FALLING   (uint16)(0x0002u)
        #define FFT_Flag_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define FFT_Flag_INTR_MASK      (0x01u) 
#endif /* (FFT_Flag__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define FFT_Flag_PS                     (* (reg8 *) FFT_Flag__PS)
/* Data Register */
#define FFT_Flag_DR                     (* (reg8 *) FFT_Flag__DR)
/* Port Number */
#define FFT_Flag_PRT_NUM                (* (reg8 *) FFT_Flag__PRT) 
/* Connect to Analog Globals */                                                  
#define FFT_Flag_AG                     (* (reg8 *) FFT_Flag__AG)                       
/* Analog MUX bux enable */
#define FFT_Flag_AMUX                   (* (reg8 *) FFT_Flag__AMUX) 
/* Bidirectional Enable */                                                        
#define FFT_Flag_BIE                    (* (reg8 *) FFT_Flag__BIE)
/* Bit-mask for Aliased Register Access */
#define FFT_Flag_BIT_MASK               (* (reg8 *) FFT_Flag__BIT_MASK)
/* Bypass Enable */
#define FFT_Flag_BYP                    (* (reg8 *) FFT_Flag__BYP)
/* Port wide control signals */                                                   
#define FFT_Flag_CTL                    (* (reg8 *) FFT_Flag__CTL)
/* Drive Modes */
#define FFT_Flag_DM0                    (* (reg8 *) FFT_Flag__DM0) 
#define FFT_Flag_DM1                    (* (reg8 *) FFT_Flag__DM1)
#define FFT_Flag_DM2                    (* (reg8 *) FFT_Flag__DM2) 
/* Input Buffer Disable Override */
#define FFT_Flag_INP_DIS                (* (reg8 *) FFT_Flag__INP_DIS)
/* LCD Common or Segment Drive */
#define FFT_Flag_LCD_COM_SEG            (* (reg8 *) FFT_Flag__LCD_COM_SEG)
/* Enable Segment LCD */
#define FFT_Flag_LCD_EN                 (* (reg8 *) FFT_Flag__LCD_EN)
/* Slew Rate Control */
#define FFT_Flag_SLW                    (* (reg8 *) FFT_Flag__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define FFT_Flag_PRTDSI__CAPS_SEL       (* (reg8 *) FFT_Flag__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define FFT_Flag_PRTDSI__DBL_SYNC_IN    (* (reg8 *) FFT_Flag__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define FFT_Flag_PRTDSI__OE_SEL0        (* (reg8 *) FFT_Flag__PRTDSI__OE_SEL0) 
#define FFT_Flag_PRTDSI__OE_SEL1        (* (reg8 *) FFT_Flag__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define FFT_Flag_PRTDSI__OUT_SEL0       (* (reg8 *) FFT_Flag__PRTDSI__OUT_SEL0) 
#define FFT_Flag_PRTDSI__OUT_SEL1       (* (reg8 *) FFT_Flag__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define FFT_Flag_PRTDSI__SYNC_OUT       (* (reg8 *) FFT_Flag__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(FFT_Flag__SIO_CFG)
    #define FFT_Flag_SIO_HYST_EN        (* (reg8 *) FFT_Flag__SIO_HYST_EN)
    #define FFT_Flag_SIO_REG_HIFREQ     (* (reg8 *) FFT_Flag__SIO_REG_HIFREQ)
    #define FFT_Flag_SIO_CFG            (* (reg8 *) FFT_Flag__SIO_CFG)
    #define FFT_Flag_SIO_DIFF           (* (reg8 *) FFT_Flag__SIO_DIFF)
#endif /* (FFT_Flag__SIO_CFG) */

/* Interrupt Registers */
#if defined(FFT_Flag__INTSTAT)
    #define FFT_Flag_INTSTAT            (* (reg8 *) FFT_Flag__INTSTAT)
    #define FFT_Flag_SNAP               (* (reg8 *) FFT_Flag__SNAP)
    
	#define FFT_Flag_0_INTTYPE_REG 		(* (reg8 *) FFT_Flag__0__INTTYPE)
#endif /* (FFT_Flag__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_FFT_Flag_H */


/* [] END OF FILE */

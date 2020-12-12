/*******************************************************************************
* File Name: TimingOutputs.h  
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

#if !defined(CY_PINS_TimingOutputs_H) /* Pins TimingOutputs_H */
#define CY_PINS_TimingOutputs_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "TimingOutputs_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 TimingOutputs__PORT == 15 && ((TimingOutputs__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    TimingOutputs_Write(uint8 value);
void    TimingOutputs_SetDriveMode(uint8 mode);
uint8   TimingOutputs_ReadDataReg(void);
uint8   TimingOutputs_Read(void);
void    TimingOutputs_SetInterruptMode(uint16 position, uint16 mode);
uint8   TimingOutputs_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the TimingOutputs_SetDriveMode() function.
     *  @{
     */
        #define TimingOutputs_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define TimingOutputs_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define TimingOutputs_DM_RES_UP          PIN_DM_RES_UP
        #define TimingOutputs_DM_RES_DWN         PIN_DM_RES_DWN
        #define TimingOutputs_DM_OD_LO           PIN_DM_OD_LO
        #define TimingOutputs_DM_OD_HI           PIN_DM_OD_HI
        #define TimingOutputs_DM_STRONG          PIN_DM_STRONG
        #define TimingOutputs_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define TimingOutputs_MASK               TimingOutputs__MASK
#define TimingOutputs_SHIFT              TimingOutputs__SHIFT
#define TimingOutputs_WIDTH              2u

/* Interrupt constants */
#if defined(TimingOutputs__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in TimingOutputs_SetInterruptMode() function.
     *  @{
     */
        #define TimingOutputs_INTR_NONE      (uint16)(0x0000u)
        #define TimingOutputs_INTR_RISING    (uint16)(0x0001u)
        #define TimingOutputs_INTR_FALLING   (uint16)(0x0002u)
        #define TimingOutputs_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define TimingOutputs_INTR_MASK      (0x01u) 
#endif /* (TimingOutputs__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TimingOutputs_PS                     (* (reg8 *) TimingOutputs__PS)
/* Data Register */
#define TimingOutputs_DR                     (* (reg8 *) TimingOutputs__DR)
/* Port Number */
#define TimingOutputs_PRT_NUM                (* (reg8 *) TimingOutputs__PRT) 
/* Connect to Analog Globals */                                                  
#define TimingOutputs_AG                     (* (reg8 *) TimingOutputs__AG)                       
/* Analog MUX bux enable */
#define TimingOutputs_AMUX                   (* (reg8 *) TimingOutputs__AMUX) 
/* Bidirectional Enable */                                                        
#define TimingOutputs_BIE                    (* (reg8 *) TimingOutputs__BIE)
/* Bit-mask for Aliased Register Access */
#define TimingOutputs_BIT_MASK               (* (reg8 *) TimingOutputs__BIT_MASK)
/* Bypass Enable */
#define TimingOutputs_BYP                    (* (reg8 *) TimingOutputs__BYP)
/* Port wide control signals */                                                   
#define TimingOutputs_CTL                    (* (reg8 *) TimingOutputs__CTL)
/* Drive Modes */
#define TimingOutputs_DM0                    (* (reg8 *) TimingOutputs__DM0) 
#define TimingOutputs_DM1                    (* (reg8 *) TimingOutputs__DM1)
#define TimingOutputs_DM2                    (* (reg8 *) TimingOutputs__DM2) 
/* Input Buffer Disable Override */
#define TimingOutputs_INP_DIS                (* (reg8 *) TimingOutputs__INP_DIS)
/* LCD Common or Segment Drive */
#define TimingOutputs_LCD_COM_SEG            (* (reg8 *) TimingOutputs__LCD_COM_SEG)
/* Enable Segment LCD */
#define TimingOutputs_LCD_EN                 (* (reg8 *) TimingOutputs__LCD_EN)
/* Slew Rate Control */
#define TimingOutputs_SLW                    (* (reg8 *) TimingOutputs__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define TimingOutputs_PRTDSI__CAPS_SEL       (* (reg8 *) TimingOutputs__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define TimingOutputs_PRTDSI__DBL_SYNC_IN    (* (reg8 *) TimingOutputs__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define TimingOutputs_PRTDSI__OE_SEL0        (* (reg8 *) TimingOutputs__PRTDSI__OE_SEL0) 
#define TimingOutputs_PRTDSI__OE_SEL1        (* (reg8 *) TimingOutputs__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define TimingOutputs_PRTDSI__OUT_SEL0       (* (reg8 *) TimingOutputs__PRTDSI__OUT_SEL0) 
#define TimingOutputs_PRTDSI__OUT_SEL1       (* (reg8 *) TimingOutputs__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define TimingOutputs_PRTDSI__SYNC_OUT       (* (reg8 *) TimingOutputs__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(TimingOutputs__SIO_CFG)
    #define TimingOutputs_SIO_HYST_EN        (* (reg8 *) TimingOutputs__SIO_HYST_EN)
    #define TimingOutputs_SIO_REG_HIFREQ     (* (reg8 *) TimingOutputs__SIO_REG_HIFREQ)
    #define TimingOutputs_SIO_CFG            (* (reg8 *) TimingOutputs__SIO_CFG)
    #define TimingOutputs_SIO_DIFF           (* (reg8 *) TimingOutputs__SIO_DIFF)
#endif /* (TimingOutputs__SIO_CFG) */

/* Interrupt Registers */
#if defined(TimingOutputs__INTSTAT)
    #define TimingOutputs_INTSTAT            (* (reg8 *) TimingOutputs__INTSTAT)
    #define TimingOutputs_SNAP               (* (reg8 *) TimingOutputs__SNAP)
    
	#define TimingOutputs_0_INTTYPE_REG 		(* (reg8 *) TimingOutputs__0__INTTYPE)
	#define TimingOutputs_1_INTTYPE_REG 		(* (reg8 *) TimingOutputs__1__INTTYPE)
#endif /* (TimingOutputs__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_TimingOutputs_H */


/* [] END OF FILE */

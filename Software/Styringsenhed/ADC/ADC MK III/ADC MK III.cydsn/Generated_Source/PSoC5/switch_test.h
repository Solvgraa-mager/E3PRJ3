/*******************************************************************************
* File Name: switch_test.h  
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

#if !defined(CY_PINS_switch_test_H) /* Pins switch_test_H */
#define CY_PINS_switch_test_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "switch_test_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 switch_test__PORT == 15 && ((switch_test__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    switch_test_Write(uint8 value);
void    switch_test_SetDriveMode(uint8 mode);
uint8   switch_test_ReadDataReg(void);
uint8   switch_test_Read(void);
void    switch_test_SetInterruptMode(uint16 position, uint16 mode);
uint8   switch_test_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the switch_test_SetDriveMode() function.
     *  @{
     */
        #define switch_test_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define switch_test_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define switch_test_DM_RES_UP          PIN_DM_RES_UP
        #define switch_test_DM_RES_DWN         PIN_DM_RES_DWN
        #define switch_test_DM_OD_LO           PIN_DM_OD_LO
        #define switch_test_DM_OD_HI           PIN_DM_OD_HI
        #define switch_test_DM_STRONG          PIN_DM_STRONG
        #define switch_test_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define switch_test_MASK               switch_test__MASK
#define switch_test_SHIFT              switch_test__SHIFT
#define switch_test_WIDTH              1u

/* Interrupt constants */
#if defined(switch_test__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in switch_test_SetInterruptMode() function.
     *  @{
     */
        #define switch_test_INTR_NONE      (uint16)(0x0000u)
        #define switch_test_INTR_RISING    (uint16)(0x0001u)
        #define switch_test_INTR_FALLING   (uint16)(0x0002u)
        #define switch_test_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define switch_test_INTR_MASK      (0x01u) 
#endif /* (switch_test__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define switch_test_PS                     (* (reg8 *) switch_test__PS)
/* Data Register */
#define switch_test_DR                     (* (reg8 *) switch_test__DR)
/* Port Number */
#define switch_test_PRT_NUM                (* (reg8 *) switch_test__PRT) 
/* Connect to Analog Globals */                                                  
#define switch_test_AG                     (* (reg8 *) switch_test__AG)                       
/* Analog MUX bux enable */
#define switch_test_AMUX                   (* (reg8 *) switch_test__AMUX) 
/* Bidirectional Enable */                                                        
#define switch_test_BIE                    (* (reg8 *) switch_test__BIE)
/* Bit-mask for Aliased Register Access */
#define switch_test_BIT_MASK               (* (reg8 *) switch_test__BIT_MASK)
/* Bypass Enable */
#define switch_test_BYP                    (* (reg8 *) switch_test__BYP)
/* Port wide control signals */                                                   
#define switch_test_CTL                    (* (reg8 *) switch_test__CTL)
/* Drive Modes */
#define switch_test_DM0                    (* (reg8 *) switch_test__DM0) 
#define switch_test_DM1                    (* (reg8 *) switch_test__DM1)
#define switch_test_DM2                    (* (reg8 *) switch_test__DM2) 
/* Input Buffer Disable Override */
#define switch_test_INP_DIS                (* (reg8 *) switch_test__INP_DIS)
/* LCD Common or Segment Drive */
#define switch_test_LCD_COM_SEG            (* (reg8 *) switch_test__LCD_COM_SEG)
/* Enable Segment LCD */
#define switch_test_LCD_EN                 (* (reg8 *) switch_test__LCD_EN)
/* Slew Rate Control */
#define switch_test_SLW                    (* (reg8 *) switch_test__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define switch_test_PRTDSI__CAPS_SEL       (* (reg8 *) switch_test__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define switch_test_PRTDSI__DBL_SYNC_IN    (* (reg8 *) switch_test__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define switch_test_PRTDSI__OE_SEL0        (* (reg8 *) switch_test__PRTDSI__OE_SEL0) 
#define switch_test_PRTDSI__OE_SEL1        (* (reg8 *) switch_test__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define switch_test_PRTDSI__OUT_SEL0       (* (reg8 *) switch_test__PRTDSI__OUT_SEL0) 
#define switch_test_PRTDSI__OUT_SEL1       (* (reg8 *) switch_test__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define switch_test_PRTDSI__SYNC_OUT       (* (reg8 *) switch_test__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(switch_test__SIO_CFG)
    #define switch_test_SIO_HYST_EN        (* (reg8 *) switch_test__SIO_HYST_EN)
    #define switch_test_SIO_REG_HIFREQ     (* (reg8 *) switch_test__SIO_REG_HIFREQ)
    #define switch_test_SIO_CFG            (* (reg8 *) switch_test__SIO_CFG)
    #define switch_test_SIO_DIFF           (* (reg8 *) switch_test__SIO_DIFF)
#endif /* (switch_test__SIO_CFG) */

/* Interrupt Registers */
#if defined(switch_test__INTSTAT)
    #define switch_test_INTSTAT            (* (reg8 *) switch_test__INTSTAT)
    #define switch_test_SNAP               (* (reg8 *) switch_test__SNAP)
    
	#define switch_test_0_INTTYPE_REG 		(* (reg8 *) switch_test__0__INTTYPE)
#endif /* (switch_test__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_switch_test_H */


/* [] END OF FILE */

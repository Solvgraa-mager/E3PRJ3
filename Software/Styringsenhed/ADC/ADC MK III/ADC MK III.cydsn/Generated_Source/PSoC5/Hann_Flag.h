/*******************************************************************************
* File Name: Hann_Flag.h  
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

#if !defined(CY_PINS_Hann_Flag_H) /* Pins Hann_Flag_H */
#define CY_PINS_Hann_Flag_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Hann_Flag_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Hann_Flag__PORT == 15 && ((Hann_Flag__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Hann_Flag_Write(uint8 value);
void    Hann_Flag_SetDriveMode(uint8 mode);
uint8   Hann_Flag_ReadDataReg(void);
uint8   Hann_Flag_Read(void);
void    Hann_Flag_SetInterruptMode(uint16 position, uint16 mode);
uint8   Hann_Flag_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Hann_Flag_SetDriveMode() function.
     *  @{
     */
        #define Hann_Flag_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Hann_Flag_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Hann_Flag_DM_RES_UP          PIN_DM_RES_UP
        #define Hann_Flag_DM_RES_DWN         PIN_DM_RES_DWN
        #define Hann_Flag_DM_OD_LO           PIN_DM_OD_LO
        #define Hann_Flag_DM_OD_HI           PIN_DM_OD_HI
        #define Hann_Flag_DM_STRONG          PIN_DM_STRONG
        #define Hann_Flag_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Hann_Flag_MASK               Hann_Flag__MASK
#define Hann_Flag_SHIFT              Hann_Flag__SHIFT
#define Hann_Flag_WIDTH              1u

/* Interrupt constants */
#if defined(Hann_Flag__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Hann_Flag_SetInterruptMode() function.
     *  @{
     */
        #define Hann_Flag_INTR_NONE      (uint16)(0x0000u)
        #define Hann_Flag_INTR_RISING    (uint16)(0x0001u)
        #define Hann_Flag_INTR_FALLING   (uint16)(0x0002u)
        #define Hann_Flag_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Hann_Flag_INTR_MASK      (0x01u) 
#endif /* (Hann_Flag__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Hann_Flag_PS                     (* (reg8 *) Hann_Flag__PS)
/* Data Register */
#define Hann_Flag_DR                     (* (reg8 *) Hann_Flag__DR)
/* Port Number */
#define Hann_Flag_PRT_NUM                (* (reg8 *) Hann_Flag__PRT) 
/* Connect to Analog Globals */                                                  
#define Hann_Flag_AG                     (* (reg8 *) Hann_Flag__AG)                       
/* Analog MUX bux enable */
#define Hann_Flag_AMUX                   (* (reg8 *) Hann_Flag__AMUX) 
/* Bidirectional Enable */                                                        
#define Hann_Flag_BIE                    (* (reg8 *) Hann_Flag__BIE)
/* Bit-mask for Aliased Register Access */
#define Hann_Flag_BIT_MASK               (* (reg8 *) Hann_Flag__BIT_MASK)
/* Bypass Enable */
#define Hann_Flag_BYP                    (* (reg8 *) Hann_Flag__BYP)
/* Port wide control signals */                                                   
#define Hann_Flag_CTL                    (* (reg8 *) Hann_Flag__CTL)
/* Drive Modes */
#define Hann_Flag_DM0                    (* (reg8 *) Hann_Flag__DM0) 
#define Hann_Flag_DM1                    (* (reg8 *) Hann_Flag__DM1)
#define Hann_Flag_DM2                    (* (reg8 *) Hann_Flag__DM2) 
/* Input Buffer Disable Override */
#define Hann_Flag_INP_DIS                (* (reg8 *) Hann_Flag__INP_DIS)
/* LCD Common or Segment Drive */
#define Hann_Flag_LCD_COM_SEG            (* (reg8 *) Hann_Flag__LCD_COM_SEG)
/* Enable Segment LCD */
#define Hann_Flag_LCD_EN                 (* (reg8 *) Hann_Flag__LCD_EN)
/* Slew Rate Control */
#define Hann_Flag_SLW                    (* (reg8 *) Hann_Flag__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Hann_Flag_PRTDSI__CAPS_SEL       (* (reg8 *) Hann_Flag__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Hann_Flag_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Hann_Flag__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Hann_Flag_PRTDSI__OE_SEL0        (* (reg8 *) Hann_Flag__PRTDSI__OE_SEL0) 
#define Hann_Flag_PRTDSI__OE_SEL1        (* (reg8 *) Hann_Flag__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Hann_Flag_PRTDSI__OUT_SEL0       (* (reg8 *) Hann_Flag__PRTDSI__OUT_SEL0) 
#define Hann_Flag_PRTDSI__OUT_SEL1       (* (reg8 *) Hann_Flag__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Hann_Flag_PRTDSI__SYNC_OUT       (* (reg8 *) Hann_Flag__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Hann_Flag__SIO_CFG)
    #define Hann_Flag_SIO_HYST_EN        (* (reg8 *) Hann_Flag__SIO_HYST_EN)
    #define Hann_Flag_SIO_REG_HIFREQ     (* (reg8 *) Hann_Flag__SIO_REG_HIFREQ)
    #define Hann_Flag_SIO_CFG            (* (reg8 *) Hann_Flag__SIO_CFG)
    #define Hann_Flag_SIO_DIFF           (* (reg8 *) Hann_Flag__SIO_DIFF)
#endif /* (Hann_Flag__SIO_CFG) */

/* Interrupt Registers */
#if defined(Hann_Flag__INTSTAT)
    #define Hann_Flag_INTSTAT            (* (reg8 *) Hann_Flag__INTSTAT)
    #define Hann_Flag_SNAP               (* (reg8 *) Hann_Flag__SNAP)
    
	#define Hann_Flag_0_INTTYPE_REG 		(* (reg8 *) Hann_Flag__0__INTTYPE)
#endif /* (Hann_Flag__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Hann_Flag_H */


/* [] END OF FILE */

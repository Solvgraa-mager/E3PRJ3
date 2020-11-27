/*******************************************************************************
* File Name: Floejtelyd.h  
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

#if !defined(CY_PINS_Floejtelyd_H) /* Pins Floejtelyd_H */
#define CY_PINS_Floejtelyd_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Floejtelyd_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Floejtelyd__PORT == 15 && ((Floejtelyd__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Floejtelyd_Write(uint8 value);
void    Floejtelyd_SetDriveMode(uint8 mode);
uint8   Floejtelyd_ReadDataReg(void);
uint8   Floejtelyd_Read(void);
void    Floejtelyd_SetInterruptMode(uint16 position, uint16 mode);
uint8   Floejtelyd_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Floejtelyd_SetDriveMode() function.
     *  @{
     */
        #define Floejtelyd_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Floejtelyd_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Floejtelyd_DM_RES_UP          PIN_DM_RES_UP
        #define Floejtelyd_DM_RES_DWN         PIN_DM_RES_DWN
        #define Floejtelyd_DM_OD_LO           PIN_DM_OD_LO
        #define Floejtelyd_DM_OD_HI           PIN_DM_OD_HI
        #define Floejtelyd_DM_STRONG          PIN_DM_STRONG
        #define Floejtelyd_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Floejtelyd_MASK               Floejtelyd__MASK
#define Floejtelyd_SHIFT              Floejtelyd__SHIFT
#define Floejtelyd_WIDTH              1u

/* Interrupt constants */
#if defined(Floejtelyd__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Floejtelyd_SetInterruptMode() function.
     *  @{
     */
        #define Floejtelyd_INTR_NONE      (uint16)(0x0000u)
        #define Floejtelyd_INTR_RISING    (uint16)(0x0001u)
        #define Floejtelyd_INTR_FALLING   (uint16)(0x0002u)
        #define Floejtelyd_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Floejtelyd_INTR_MASK      (0x01u) 
#endif /* (Floejtelyd__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Floejtelyd_PS                     (* (reg8 *) Floejtelyd__PS)
/* Data Register */
#define Floejtelyd_DR                     (* (reg8 *) Floejtelyd__DR)
/* Port Number */
#define Floejtelyd_PRT_NUM                (* (reg8 *) Floejtelyd__PRT) 
/* Connect to Analog Globals */                                                  
#define Floejtelyd_AG                     (* (reg8 *) Floejtelyd__AG)                       
/* Analog MUX bux enable */
#define Floejtelyd_AMUX                   (* (reg8 *) Floejtelyd__AMUX) 
/* Bidirectional Enable */                                                        
#define Floejtelyd_BIE                    (* (reg8 *) Floejtelyd__BIE)
/* Bit-mask for Aliased Register Access */
#define Floejtelyd_BIT_MASK               (* (reg8 *) Floejtelyd__BIT_MASK)
/* Bypass Enable */
#define Floejtelyd_BYP                    (* (reg8 *) Floejtelyd__BYP)
/* Port wide control signals */                                                   
#define Floejtelyd_CTL                    (* (reg8 *) Floejtelyd__CTL)
/* Drive Modes */
#define Floejtelyd_DM0                    (* (reg8 *) Floejtelyd__DM0) 
#define Floejtelyd_DM1                    (* (reg8 *) Floejtelyd__DM1)
#define Floejtelyd_DM2                    (* (reg8 *) Floejtelyd__DM2) 
/* Input Buffer Disable Override */
#define Floejtelyd_INP_DIS                (* (reg8 *) Floejtelyd__INP_DIS)
/* LCD Common or Segment Drive */
#define Floejtelyd_LCD_COM_SEG            (* (reg8 *) Floejtelyd__LCD_COM_SEG)
/* Enable Segment LCD */
#define Floejtelyd_LCD_EN                 (* (reg8 *) Floejtelyd__LCD_EN)
/* Slew Rate Control */
#define Floejtelyd_SLW                    (* (reg8 *) Floejtelyd__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Floejtelyd_PRTDSI__CAPS_SEL       (* (reg8 *) Floejtelyd__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Floejtelyd_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Floejtelyd__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Floejtelyd_PRTDSI__OE_SEL0        (* (reg8 *) Floejtelyd__PRTDSI__OE_SEL0) 
#define Floejtelyd_PRTDSI__OE_SEL1        (* (reg8 *) Floejtelyd__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Floejtelyd_PRTDSI__OUT_SEL0       (* (reg8 *) Floejtelyd__PRTDSI__OUT_SEL0) 
#define Floejtelyd_PRTDSI__OUT_SEL1       (* (reg8 *) Floejtelyd__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Floejtelyd_PRTDSI__SYNC_OUT       (* (reg8 *) Floejtelyd__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Floejtelyd__SIO_CFG)
    #define Floejtelyd_SIO_HYST_EN        (* (reg8 *) Floejtelyd__SIO_HYST_EN)
    #define Floejtelyd_SIO_REG_HIFREQ     (* (reg8 *) Floejtelyd__SIO_REG_HIFREQ)
    #define Floejtelyd_SIO_CFG            (* (reg8 *) Floejtelyd__SIO_CFG)
    #define Floejtelyd_SIO_DIFF           (* (reg8 *) Floejtelyd__SIO_DIFF)
#endif /* (Floejtelyd__SIO_CFG) */

/* Interrupt Registers */
#if defined(Floejtelyd__INTSTAT)
    #define Floejtelyd_INTSTAT            (* (reg8 *) Floejtelyd__INTSTAT)
    #define Floejtelyd_SNAP               (* (reg8 *) Floejtelyd__SNAP)
    
	#define Floejtelyd_0_INTTYPE_REG 		(* (reg8 *) Floejtelyd__0__INTTYPE)
#endif /* (Floejtelyd__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Floejtelyd_H */


/* [] END OF FILE */

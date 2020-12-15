/*******************************************************************************
* File Name: RX_ISR.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_RX_ISR_H)
#define CY_ISR_RX_ISR_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void RX_ISR_Start(void);
void RX_ISR_StartEx(cyisraddress address);
void RX_ISR_Stop(void);

CY_ISR_PROTO(RX_ISR_Interrupt);

void RX_ISR_SetVector(cyisraddress address);
cyisraddress RX_ISR_GetVector(void);

void RX_ISR_SetPriority(uint8 priority);
uint8 RX_ISR_GetPriority(void);

void RX_ISR_Enable(void);
uint8 RX_ISR_GetState(void);
void RX_ISR_Disable(void);

void RX_ISR_SetPending(void);
void RX_ISR_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the RX_ISR ISR. */
#define RX_ISR_INTC_VECTOR            ((reg32 *) RX_ISR__INTC_VECT)

/* Address of the RX_ISR ISR priority. */
#define RX_ISR_INTC_PRIOR             ((reg8 *) RX_ISR__INTC_PRIOR_REG)

/* Priority of the RX_ISR interrupt. */
#define RX_ISR_INTC_PRIOR_NUMBER      RX_ISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable RX_ISR interrupt. */
#define RX_ISR_INTC_SET_EN            ((reg32 *) RX_ISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the RX_ISR interrupt. */
#define RX_ISR_INTC_CLR_EN            ((reg32 *) RX_ISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the RX_ISR interrupt state to pending. */
#define RX_ISR_INTC_SET_PD            ((reg32 *) RX_ISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the RX_ISR interrupt. */
#define RX_ISR_INTC_CLR_PD            ((reg32 *) RX_ISR__INTC_CLR_PD_REG)


#endif /* CY_ISR_RX_ISR_H */


/* [] END OF FILE */

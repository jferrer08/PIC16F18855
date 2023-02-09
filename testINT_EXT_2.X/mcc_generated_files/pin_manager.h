/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F18855
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set btnSuma aliases
#define btnSuma_TRIS                 TRISBbits.TRISB0
#define btnSuma_LAT                  LATBbits.LATB0
#define btnSuma_PORT                 PORTBbits.RB0
#define btnSuma_WPU                  WPUBbits.WPUB0
#define btnSuma_OD                   ODCONBbits.ODCB0
#define btnSuma_ANS                  ANSELBbits.ANSB0
#define btnSuma_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define btnSuma_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define btnSuma_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define btnSuma_GetValue()           PORTBbits.RB0
#define btnSuma_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define btnSuma_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define btnSuma_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define btnSuma_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define btnSuma_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define btnSuma_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define btnSuma_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define btnSuma_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set btnResta aliases
#define btnResta_TRIS                 TRISBbits.TRISB1
#define btnResta_LAT                  LATBbits.LATB1
#define btnResta_PORT                 PORTBbits.RB1
#define btnResta_WPU                  WPUBbits.WPUB1
#define btnResta_OD                   ODCONBbits.ODCB1
#define btnResta_ANS                  ANSELBbits.ANSB1
#define btnResta_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define btnResta_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define btnResta_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define btnResta_GetValue()           PORTBbits.RB1
#define btnResta_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define btnResta_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define btnResta_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define btnResta_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define btnResta_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define btnResta_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define btnResta_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define btnResta_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF0 pin functionality
 * @Example
    IOCBF0_ISR();
 */
void IOCBF0_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF0 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF0 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF0_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF0_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF0 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF0_SetInterruptHandler() method.
    This handler is called every time the IOCBF0 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF0_SetInterruptHandler(IOCBF0_InterruptHandler);

*/
extern void (*IOCBF0_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF0 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF0_SetInterruptHandler() method.
    This handler is called every time the IOCBF0 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF0_SetInterruptHandler(IOCBF0_DefaultInterruptHandler);

*/
void IOCBF0_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF1 pin functionality
 * @Example
    IOCBF1_ISR();
 */
void IOCBF1_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF1 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF1 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF1_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF1 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF1_SetInterruptHandler() method.
    This handler is called every time the IOCBF1 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF1_SetInterruptHandler(IOCBF1_InterruptHandler);

*/
extern void (*IOCBF1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF1 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF1_SetInterruptHandler() method.
    This handler is called every time the IOCBF1 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF1_SetInterruptHandler(IOCBF1_DefaultInterruptHandler);

*/
void IOCBF1_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/
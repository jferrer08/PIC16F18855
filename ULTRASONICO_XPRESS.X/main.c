/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F18855
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */

//Pines para la LCD
#define RS  LATBbits.LATB0
#define EN  LATBbits.LATB1
#define D4  LATBbits.LATB2
#define D5  LATBbits.LATB3
#define D6  LATBbits.LATB4
#define D7  LATBbits.LATB5

#define ECHO PORTAbits.RA6
#define TRIG LATAbits.LATA7

#include "lcd.h"
#include <stdio.h>
char aux[20];

float distancia = 0;
int t_low = 0;
int t_high = 0;

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    ANSELA = 0x00;
    TRISAbits.TRISA6 = 1;
    TRISAbits.TRISA7 = 0;
    
    T1CON = 0x33;
    T1CLK = 1;
    
    TRISB = 0x00;
    LATB = 0x00;
    
    Lcd_Init();
    Lcd_Clear();
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String("Ultrasonico");
        
    while (1)
    {
        // Add your application code
        TRIG = 1;
        __delay_us(10);
        TRIG = 0;
        while(ECHO == 0);
        TMR1H = 0x00;
        TMR1L = 0x00;
        while(ECHO == 1);
        
        //TMR1_StartTimer();
        
        t_low = TMR1L;
        t_high = TMR1H;
        
        Lcd_Set_Cursor(2,1);        
        distancia = (((t_high<<8)+t_low)*0.004*34.0)/2.0;
        sprintf(aux,"Dist. = %0.2f    ",distancia);
        Lcd_Write_String(aux);
        __delay_ms(200);
    }
}
/**
 End of File
*/
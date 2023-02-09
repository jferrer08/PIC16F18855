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

#define RS LATBbits.LATB0
#define EN LATBbits.LATB1
#define D4 LATBbits.LATB2
#define D5 LATBbits.LATB3
#define D6 LATBbits.LATB4
#define D7 LATBbits.LATB5

#include "lcd.h"
#include <stdio.h>

char aux[20];

int valorADC;

/*
                         Main application
 */
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
    
    INTCONbits.GIE = 1;     //habilitacion global de interrupciones
    INTCONbits.PEIE = 1;    //habilitacion de interrupciones perifericas
    
    PIR1bits.ADIF = 0;      //limpio bandera de interrupcion
    PIE1bits.ADIE = 1;      //habilita interrupción de adc
    
    ADCON0 = 0x84;          //habilita adc,justificacion derecha
    ADCON1 = 0x00;          //
    ADCON2 = 0x00;          //modo basico
    ADCON3 = 0x00;          //deshabilita ADTIF
    ADCLK = 0x01;           //fosc/4
    ADREF = 0x00;           //vref- y vref+ de pic
    ADACQ = 0x01;           //adquisicion del clock de adc
    ADPCH = 0x04;           //canal RA4
    
    TRISB = 0x00;           //configuracion para lcd
    ANSELB = 0x00;
    LATB = 0x00;
    
    ADCON0bits.ADON = 1;    //activa adc
    __delay_us(30);
    ADCON0bits.ADGO = 1;    //inicia conversion
    
    Lcd_Init();
    
    while (1)
    {
        // Add your application code
        Lcd_Clear();
        Lcd_Set_Cursor(1,1);
        sprintf(aux,"Valor: %d  ", valorADC);
        Lcd_Write_String(aux);
        __delay_ms(100);
    }
}
/**
 End of File
*/

void __interrupt() adc(){
    if(PIR1bits.ADIF == 1){     //ejecucion de interrupcion
        ADCON0bits.ADON = 0;    //deshabilita adc
        valorADC = (ADRESH << 8) + ADRESL;  //agrupa resultado
        ADCON0bits.ADON = 1;    //habilita ADC
        __delay_us(30);
        ADCON0bits.ADGO = 1;    //inicia conversion
        PIR1bits.ADIF = 0;      //limpia bandera interrupcion
    }
}
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

int edoAnte = 1;
void temporizador(unsigned int segundos);

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
    
    //configuracion de puerto para LCD
    TRISB = 0x00;
    LATB = 0x00;
    ANSELB = 0x00;
    
    //configuracion de salida
    TRISAbits.TRISA0 = 0;
    ANSELAbits.ANSA0 = 0;
    
    //configuracion de entrada pull up
    TRISAbits.TRISA5 = 1;
    ANSELAbits.ANSA5 = 0;
    WPUAbits.WPUA5 = 1;
    
    //inicializacion de lcd
    Lcd_Init();
    Lcd_Clear();
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String("Tiempo: ");
    
    while (1)
    {
        // Add your application code
        int lectura = PORTAbits.RA5;
        if(lectura != edoAnte){
            if(lectura == 0){
                __delay_ms(200);
                while(!PORTAbits.RA5);
                LATAbits.LATA0 = 1;
                Lcd_Set_Cursor(2,5);
                Lcd_Write_String("5 Segundos");
                temporizador(5);
                LATAbits.LATA0 = 0;
                Lcd_Set_Cursor(2,5);
                Lcd_Write_String("Terminado  ");
            }
        }
    }
}
/**
 End of File
*/

void temporizador(unsigned int segundos){
    unsigned int i = 0;
    T0CON0 = 0x90;  //configuracion de TMR0
    T0CON1 = 0x45;
    for(i=0; i<segundos; i++){
        TMR0 = 3035;    //Carga de TMR0 para trabajar a 1 segundo
        while(!PIR0bits.TMR0IF);    //Hasta que se desborde TMR0
        PIR0bits.TMR0IF = 0;        //limpio bandera
    }
    T0CON0 = 0; //desactivo TMR0
    T0CON1 = 0;
}
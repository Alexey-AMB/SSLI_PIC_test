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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.0
        Device            :  PIC16LF15354
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.35	
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

// get/set IO_RA0_PE1 aliases
#define IO_RA0_PE1_TRIS                 TRISAbits.TRISA0
#define IO_RA0_PE1_LAT                  LATAbits.LATA0
#define IO_RA0_PE1_PORT                 PORTAbits.RA0
#define IO_RA0_PE1_WPU                  WPUAbits.WPUA0
#define IO_RA0_PE1_OD                   ODCONAbits.ODCA0
#define IO_RA0_PE1_ANS                  ANSELAbits.ANSA0
#define IO_RA0_PE1_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define IO_RA0_PE1_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define IO_RA0_PE1_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define IO_RA0_PE1_GetValue()           PORTAbits.RA0
#define IO_RA0_PE1_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define IO_RA0_PE1_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define IO_RA0_PE1_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define IO_RA0_PE1_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define IO_RA0_PE1_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define IO_RA0_PE1_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define IO_RA0_PE1_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define IO_RA0_PE1_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set IO_RA1_PE2 aliases
#define IO_RA1_PE2_TRIS                 TRISAbits.TRISA1
#define IO_RA1_PE2_LAT                  LATAbits.LATA1
#define IO_RA1_PE2_PORT                 PORTAbits.RA1
#define IO_RA1_PE2_WPU                  WPUAbits.WPUA1
#define IO_RA1_PE2_OD                   ODCONAbits.ODCA1
#define IO_RA1_PE2_ANS                  ANSELAbits.ANSA1
#define IO_RA1_PE2_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define IO_RA1_PE2_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define IO_RA1_PE2_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define IO_RA1_PE2_GetValue()           PORTAbits.RA1
#define IO_RA1_PE2_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define IO_RA1_PE2_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define IO_RA1_PE2_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define IO_RA1_PE2_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define IO_RA1_PE2_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define IO_RA1_PE2_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define IO_RA1_PE2_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define IO_RA1_PE2_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set IO_RA2_PE3 aliases
#define IO_RA2_PE3_TRIS                 TRISAbits.TRISA2
#define IO_RA2_PE3_LAT                  LATAbits.LATA2
#define IO_RA2_PE3_PORT                 PORTAbits.RA2
#define IO_RA2_PE3_WPU                  WPUAbits.WPUA2
#define IO_RA2_PE3_OD                   ODCONAbits.ODCA2
#define IO_RA2_PE3_ANS                  ANSELAbits.ANSA2
#define IO_RA2_PE3_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define IO_RA2_PE3_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define IO_RA2_PE3_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define IO_RA2_PE3_GetValue()           PORTAbits.RA2
#define IO_RA2_PE3_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define IO_RA2_PE3_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define IO_RA2_PE3_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define IO_RA2_PE3_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define IO_RA2_PE3_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define IO_RA2_PE3_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define IO_RA2_PE3_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define IO_RA2_PE3_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set IO_RA3_PE4 aliases
#define IO_RA3_PE4_TRIS                 TRISAbits.TRISA3
#define IO_RA3_PE4_LAT                  LATAbits.LATA3
#define IO_RA3_PE4_PORT                 PORTAbits.RA3
#define IO_RA3_PE4_WPU                  WPUAbits.WPUA3
#define IO_RA3_PE4_OD                   ODCONAbits.ODCA3
#define IO_RA3_PE4_ANS                  ANSELAbits.ANSA3
#define IO_RA3_PE4_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define IO_RA3_PE4_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define IO_RA3_PE4_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define IO_RA3_PE4_GetValue()           PORTAbits.RA3
#define IO_RA3_PE4_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define IO_RA3_PE4_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define IO_RA3_PE4_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define IO_RA3_PE4_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define IO_RA3_PE4_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define IO_RA3_PE4_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define IO_RA3_PE4_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define IO_RA3_PE4_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set IO_RA4_PE5 aliases
#define IO_RA4_PE5_TRIS                 TRISAbits.TRISA4
#define IO_RA4_PE5_LAT                  LATAbits.LATA4
#define IO_RA4_PE5_PORT                 PORTAbits.RA4
#define IO_RA4_PE5_WPU                  WPUAbits.WPUA4
#define IO_RA4_PE5_OD                   ODCONAbits.ODCA4
#define IO_RA4_PE5_ANS                  ANSELAbits.ANSA4
#define IO_RA4_PE5_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define IO_RA4_PE5_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define IO_RA4_PE5_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define IO_RA4_PE5_GetValue()           PORTAbits.RA4
#define IO_RA4_PE5_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define IO_RA4_PE5_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define IO_RA4_PE5_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define IO_RA4_PE5_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define IO_RA4_PE5_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define IO_RA4_PE5_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define IO_RA4_PE5_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define IO_RA4_PE5_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set IO_RA5_RP_RES aliases
#define IO_RA5_RP_RES_TRIS                 TRISAbits.TRISA5
#define IO_RA5_RP_RES_LAT                  LATAbits.LATA5
#define IO_RA5_RP_RES_PORT                 PORTAbits.RA5
#define IO_RA5_RP_RES_WPU                  WPUAbits.WPUA5
#define IO_RA5_RP_RES_OD                   ODCONAbits.ODCA5
#define IO_RA5_RP_RES_ANS                  ANSELAbits.ANSA5
#define IO_RA5_RP_RES_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define IO_RA5_RP_RES_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define IO_RA5_RP_RES_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define IO_RA5_RP_RES_GetValue()           PORTAbits.RA5
#define IO_RA5_RP_RES_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define IO_RA5_RP_RES_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define IO_RA5_RP_RES_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define IO_RA5_RP_RES_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define IO_RA5_RP_RES_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define IO_RA5_RP_RES_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define IO_RA5_RP_RES_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define IO_RA5_RP_RES_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set IO_RB4 aliases
#define IO_RB4_TRIS                 TRISBbits.TRISB4
#define IO_RB4_LAT                  LATBbits.LATB4
#define IO_RB4_PORT                 PORTBbits.RB4
#define IO_RB4_WPU                  WPUBbits.WPUB4
#define IO_RB4_OD                   ODCONBbits.ODCB4
#define IO_RB4_ANS                  ANSELBbits.ANSB4
#define IO_RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IO_RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IO_RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IO_RB4_GetValue()           PORTBbits.RB4
#define IO_RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define IO_RB4_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define IO_RB4_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define IO_RB4_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define IO_RB4_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define IO_RB4_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode()         do { ANSELCbits.ANSC0 = 1; } while(0)
#define RC0_SetDigitalMode()        do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSC7 = 0; } while(0)

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



#endif // PIN_MANAGER_H
/**
 End of File
*/
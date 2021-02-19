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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.0
        Device            :  PIC16LF15354
        Driver Version    :  2.00
 */

//tmr0 1 tick = 1.024 mS
//Quartz 16M system clock 4M

#include "myroutines.h"
#include "commands.h"
#include "mcc_generated_files/mcc.h"

/** V A R I A B L E S ********************************************************/
stInterrupt IntrChanged;

uint16_t sId[8];
uint16_t iSerNum;
uint8_t iCurrTerm;
uint8_t arRecivBuff1[20]; // __at(0x100); // >= 16 + 4
uint8_t arRecivBuff2[32]; // __at(0x120); // >= 25 + 4
uint8_t arSendBuff1[32]; //>=AnsStatus + 4
uint8_t arSendBuff2[32];
AnsStatus anStat;

/** D E C L A R A T I O N S **************************************************/
void My_Initialise()
{
    iCurrTerm = 0;
    memset(arRecivBuff1, 0, sizeof (arRecivBuff1));
    memset(arRecivBuff2, 0, sizeof (arRecivBuff2));
    memset(&anStat, 0, sizeof (anStat));

    IntrChanged.bIntrUsart1 = false;
    IntrChanged.bIntrUsart2 = false;

    ReadMyFlash();

    TMR0_StopTimer();
    PIR0bits.TMR0IF = 0;
}

void SendMessage1(UsartCommand ans, void* data, uint8_t lendata)
{
    uint8_t i = 0;
    uint8_t lenmess = lendata + 4;
    memset(arSendBuff1, 0, lenmess);

    arSendBuff1[0] = 0x0A;
    arSendBuff1[1] = lenmess;
    arSendBuff1[2] = ans;
    memcpy(arSendBuff1 + 3, data, lendata);
    arSendBuff1[lendata + 3] = GetCRC8(arSendBuff1 + 2, lendata + 1);

    for (i = 0; i < lenmess; i++)
    {
        while (!EUSART1_is_tx_ready()) NOP();
        EUSART1_Write(arSendBuff1[i]);
        while (!EUSART1_is_tx_done()) NOP();
    }
}

//void SendCurrArStatus1(void)
//{
//    uint8_t i = 0;
//    uint8_t crc = 0;
//    crc = GetCRC8((uint8_t *) arStat, sizeof (arStat)) + ANS_ARSTAT;
//    while (!EUSART1_is_tx_ready()) NOP();
//    EUSART1_Write(0x0A);
//    while (!EUSART1_is_tx_done()) NOP();
//    while (!EUSART1_is_tx_ready()) NOP();
//    EUSART1_Write(sizeof (arStat) + 4);
//    while (!EUSART1_is_tx_done()) NOP();
//    while (!EUSART1_is_tx_ready()) NOP();
//    EUSART1_Write(ANS_ARSTAT);
//    while (!EUSART1_is_tx_done()) NOP();
//    for (i = 0; i < sizeof (arStat); i++)
//    {
//        while (!EUSART1_is_tx_ready()) NOP();
//        EUSART1_Write(*((uint8_t *) arStat + i));
//        while (!EUSART1_is_tx_done()) NOP();
//    }
//    while (!EUSART1_is_tx_ready()) NOP();
//    EUSART1_Write(crc);
//    while (!EUSART1_is_tx_done()) NOP();
//}

void SendMessage2(UsartCommand ans, void* data, uint8_t lendata)
{
    uint8_t i = 0;
    uint8_t lenmess = lendata + 4;
    memset(arSendBuff2, 0, lenmess);

    arSendBuff2[0] = 0x0A;
    arSendBuff2[1] = lenmess;
    arSendBuff2[2] = ans;
    memcpy(arSendBuff2 + 3, data, lendata);
    arSendBuff2[lendata + 3] = GetCRC8(arSendBuff2 + 2, lendata + 1);

    for (i = 0; i < lenmess; i++)
    {
        while (!EUSART2_is_tx_ready()) NOP();
        EUSART2_Write(arSendBuff2[i]);
        while (!EUSART2_is_tx_done()) NOP();
    }
}

//Переключаем USART2 на разные лапки Пика.
void ToggleUsart2Pins(uint8_t num)
{
    INTERRUPT_GlobalInterruptDisable();
    INTERRUPT_PeripheralInterruptDisable();
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCK = 0x00; // unlock PPS

    //не используемые выходы как обычные порты, иначе будет дублирование
    RC1PPS = 0x00;
    RC3PPS = 0x00;
    RC5PPS = 0x00;
    RB1PPS = 0x00;
    RB3PPS = 0x00;
    //все не используемые выходы на "вход"
    TRISCbits.TRISC1 = 1;
    TRISCbits.TRISC3 = 1;
    TRISCbits.TRISC5 = 1;
    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB3 = 1;

    switch (num)
    {
        case 0:
            TRISCbits.TRISC0 = 1;
            RX2DTPPS = 0x10; //in EUSART2:RX2
            TRISCbits.TRISC1 = 0;
            RC1PPS = 0x11; //out EUSART2:TX2
            break;
        case 1:
            TRISCbits.TRISC2 = 1;
            RX2DTPPS = 0x12; //in EUSART2:RX2
            TRISCbits.TRISC3 = 0;
            RC3PPS = 0x11; //out EUSART2:TX2
            break;
        case 2:
            TRISCbits.TRISC4 = 1;
            RX2DTPPS = 0x14; //in EUSART2:RX2
            TRISCbits.TRISC5 = 0;
            RC5PPS = 0x11; //out EUSART2:TX2
            break;
        case 3:
            TRISBbits.TRISB0 = 1;
            RX2DTPPS = 0x08; //in EUSART2:RX2
            TRISBbits.TRISB1 = 0;
            RB1PPS = 0x11; //out EUSART2:TX2
            break;
        case 4:
            TRISBbits.TRISB2 = 1;
            RX2DTPPS = 0x0A; //in EUSART2:RX2
            TRISBbits.TRISB3 = 0;
            RB3PPS = 0x11; //out EUSART2:TX2
            break;
        default:
            break;
    }

    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCK = 0x01; // lock   PPS
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    EUSART2_Initialize();
}

//включает и выключает питание на заданный слот
void PowerOnTerm(uint8_t num, bool bPower)
{
    switch (num)
    {
        case 0:
            LATAbits.LATA0 = bPower;
            break;
        case 1:
            LATAbits.LATA1 = bPower;
            break;
        case 2:
            LATAbits.LATA2 = bPower;
            break;
        case 3:
            LATAbits.LATA3 = bPower;
            break;
        case 4:
            LATAbits.LATA4 = bPower;
            break;
        default:
            break;
    }
}

void WorkWithBlock1(void)
{ //команды с малины
    switch (arRecivBuff1[0])
    {
        case CMD_TEST:
            SendMessage1((UsartCommand)ANS_OK, NULL, 0);
            break;
        case CMD_SET_SERNUM:
            memcpy(&iSerNum, arRecivBuff1 + 1, sizeof (uint16_t));
            WriteMyFlash();
            break;
        case CMD_SET_ID:
            memcpy(sId, arRecivBuff1 + 1, sizeof (sId));
            WriteMyFlash();
            break;
        case CMD_GET_SERNUM:
            ReadMyFlash();
            SendMessage1((UsartCommand)ANS_SERNUM, &iSerNum, sizeof (uint16_t));
            break;
        case CMD_GET_ID:
            ReadMyFlash();
            SendMessage1((UsartCommand)ANS_ID, sId, sizeof (sId));
            break;
        case CMDRAS_GET_STATUS:
            ToggleUsart2Pins(arRecivBuff1[1]);
            __delay_ms(10);
            SendMessage2(CMD_GET_STATUS, NULL, 0);
            break;
        case CMDRAS_SET_IP:
            ToggleUsart2Pins(arRecivBuff1[1]);
            __delay_ms(10);
            SendMessage2(CMD_SET_IP, arRecivBuff1 + 2, 2);
            break;
        case CMDRAS_SET_UPDSTRT:
            ToggleUsart2Pins(arRecivBuff1[1]);
            __delay_ms(10);
            SendMessage2(CMDRAS_SET_UPDSTRT, NULL, 0);
            break;
            
        case CMDRAS_CHRG_EN:
            ToggleUsart2Pins(arRecivBuff1[1]);
            __delay_ms(10);
            SendMessage2(CMD_CHRG_EN, NULL, 0);
            break;
        case CMDRAS_CHRG_DIS:
            ToggleUsart2Pins(arRecivBuff1[1]);
            __delay_ms(10);
            SendMessage2(CMD_CHRG_DIS, NULL, 0);
            break;
        case CMDRAS_USBA_EN:
            ToggleUsart2Pins(arRecivBuff1[1]);
            __delay_ms(10);
            SendMessage2(CMD_USBA_EN, NULL, 0);
            break;
        case CMDRAS_USBA_DIS:
            ToggleUsart2Pins(arRecivBuff1[1]);
            __delay_ms(10);
            SendMessage2(CMD_USBA_DIS, NULL, 0);
            break;
        case CMDRAS_USBOE_EN:
            ToggleUsart2Pins(arRecivBuff1[1]);
            __delay_ms(10);
            SendMessage2(CMD_USB_OE_EN, NULL, 0);
            break;
        case CMDRAS_USBOE_DIS:
            ToggleUsart2Pins(arRecivBuff1[1]);
            __delay_ms(10);
            SendMessage2(CMD_USB_OE_DIS, NULL, 0);
            break;
        case CMDRAS_LED_R_ON:
            ToggleUsart2Pins(arRecivBuff1[1]);
            __delay_ms(10);
            SendMessage2(CMD_LED_R_ON, NULL, 0);
            break;
        case CMDRAS_LED_R_OFF:
            ToggleUsart2Pins(arRecivBuff1[1]);
            __delay_ms(10);
            SendMessage2(CMD_LED_R_OFF, NULL, 0);
            break;
        case CMDRAS_LED_G_ON:
            ToggleUsart2Pins(arRecivBuff1[1]);
            __delay_ms(10);
            SendMessage2(CMD_LED_G_ON, NULL, 0);
            break;
        case CMDRAS_LED_G_OFF:
            ToggleUsart2Pins(arRecivBuff1[1]);
            __delay_ms(10);
            SendMessage2(CMD_LED_G_OFF, NULL, 0);
            break;
        case CMDRAS_SC_SLEEP:
            ToggleUsart2Pins(arRecivBuff1[1]);
            __delay_ms(10);
            SendMessage2(CMD_SC_SLEEP, NULL, 0);
            break;
        case CMDRAS_SC_RUN:
            ToggleUsart2Pins(arRecivBuff1[1]);
            __delay_ms(10);
            SendMessage2(CMD_SC_RUN, NULL, 0);
            break;
        case CMDRAS_SC_DOWN:
            ToggleUsart2Pins(arRecivBuff1[1]);
            __delay_ms(10);
            SendMessage2(CMD_SC_DOWN, NULL, 0);
            break;
        case CMDRAS_SC_REBOOT:
            ToggleUsart2Pins(arRecivBuff1[1]);
            __delay_ms(10);
            SendMessage2(CMD_SC_REBOOT, NULL, 0);
            break;
        case CMDRAS_GET_AKKPRCNT:
            ToggleUsart2Pins(arRecivBuff1[1]);
            __delay_ms(10);
            SendMessage2(CMD_GET_AKKPRCNT, NULL, 0);
            break;
        case CMDRAS_SET_ID:
            ToggleUsart2Pins(arRecivBuff1[1]);
            __delay_ms(10);
            SendMessage2(CMD_SET_ID, arRecivBuff1 + 2, 16);
            break;    
        case CMDRAS_SET_SERNUM:
            ToggleUsart2Pins(arRecivBuff1[1]);
            __delay_ms(10);
            SendMessage2(CMD_SET_SERNUM, arRecivBuff1 + 2, 2);
            break;     
            
        case CMDRAS_SLOT_PWRON:
            PowerOnTerm(arRecivBuff1[1], true);
            break;
        case CMDRAS_SLOT_PWROFF:
            PowerOnTerm(arRecivBuff1[1], false);
            break;
        case CMDRAS_RASP_REBOOT:
            LATAbits.LATA5 = 0;
            TMR0_WriteTimer(0xFC17); //timeout ~1 sec.
            PIR0bits.TMR0IF = 0;
            TMR0_StartTimer();
            while (!PIR0bits.TMR0IF) NOP();
            TMR0_StopTimer();
            PIR0bits.TMR0IF = 0;
            LATAbits.LATA5 = 1;
            break;
        default:
            break;
    }
}

void WorkWithBlock2(void)
{ //ответы с терминала
    //uint8_t i = 0;
    switch (arRecivBuff2[0])
    {
        case CMD_TEST: //test only
            SendMessage2((UsartCommand)ANS_OK, NULL, 0);
            break;
        case ANS_OK:
            //SendMessage2(ANS_OK, NULL, 0);
            break;
        case ANS_ERROR:
            //SendMessage2(ANS_ERROR, NULL, 0);
            break;
        case ANS_STATUS: //anStat + (iCurrTerm * sizeof (AnsStatus))
            memcpy(&anStat, arRecivBuff2 + 1, sizeof (AnsStatus));
            break;
        default:
            break;
    }
}

/** M A I N ******************************************************************/
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    My_Initialise();

    while (1)
    {
        if (IntrChanged.bIntrUsart1)
        {
            WorkWithBlock1(); //команды с малины
            IntrChanged.bIntrUsart1 = false;
            //__delay_ms(10); //если идет передача
            IO_RB4_Toggle(); //Red LED - Test_only
        }
        
        if (IntrChanged.bIntrUsart2)
        {
            WorkWithBlock2(); //ответы с терминала
            IntrChanged.bIntrUsart2 = false;
            //__delay_ms(10); //если идет передача
        }
        __delay_ms(10);
        
//        for (iCurrTerm = 0; iCurrTerm < 5; iCurrTerm++)
//        {
//            IO_RB4_Toggle();    //Red LED
//
//            PowerOnTerm(iCurrTerm, true);   //терминал может быть разряжен в хлам.
//            ToggleUsart2Pins(iCurrTerm);
//            __delay_ms(10);
//            SendMessage2((UsartAnswer) CMD_GET_STATUS, NULL, 0);
//            TMR0_WriteTimer(0xFC17); //timeout ~1 sec.
//            TMR0_StartTimer();
//            memset((void *) anStat, 0, sizeof (AnsStatus));
//            while (!PIR0bits.TMR0IF /*|| IntrChanged.bIntrUsart2 */) NOP();
//            TMR0_StopTimer();
//            PIR0bits.TMR0IF = 0;
//            if (!IntrChanged.bIntrUsart2)
//            {
//                PowerOnTerm(iCurrTerm, false);
//            }
//            else
//            {
//                WorkWithBlock2();   //команды с терминала
//                IntrChanged.bIntrUsart2 = false;
//                //PowerOnTerm(iCurrTerm, true); test only!!!
//            }
//
//            if (IntrChanged.bIntrUsart1)
//            {
//                WorkWithBlock1();   //команды с малины
//                IntrChanged.bIntrUsart1 = false;
//            }
//        }
    }
}

/**
 End of File
 */
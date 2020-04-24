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
uint8_t arRecivBuff1[20]; // __at(0x100);
uint8_t arRecivBuff2[20]; // __at(0x120);
uint8_t arSendBuff1[30];
uint8_t arSendBuff2[30];

/** D E C L A R A T I O N S **************************************************/
void My_Initialise()
{
    memset(arRecivBuff1, 0, sizeof (arRecivBuff1));
    memset(arRecivBuff2, 0, sizeof (arRecivBuff2));

    IntrChanged.bIntrPin = false;
    IntrChanged.bIntrUsart1 = false;
    IntrChanged.bIntrUsart2 = false;

    ReadMyFlash();
}

void SendMessage1(UsartAnswer ans, void* data, uint8_t lendata)
{
    uint8_t i = 0;
    uint8_t lenmess = lendata + 4;
    memset(arSendBuff1, 0, lenmess);

    arSendBuff1[0] = 0x0A;
    arSendBuff1[1] = lenmess;
    arSendBuff1[2] = ans;
    memcpy(arSendBuff1, data, lendata);
    arSendBuff1[lendata + 3] = GetCRC8(arSendBuff1 + 2, lendata + 1);

    for (i = 0; i < lenmess; i++)
    {
        if (EUSART1_is_tx_ready())
        {
            EUSART1_Write(arSendBuff1[i]);
            while (!EUSART1_is_tx_done()) NOP();
        }
    }
}

void SendMessage2(UsartAnswer ans, void* data, uint8_t lendata)
{
    uint8_t i = 0;
    uint8_t lenmess = lendata + 4;
    memset(arSendBuff2, 0, lenmess);

    arSendBuff2[0] = 0x0A;
    arSendBuff2[1] = lenmess;
    arSendBuff2[2] = ans;
    memcpy(arSendBuff2, data, lendata);
    arSendBuff2[lendata + 3] = GetCRC8(arSendBuff2 + 2, lendata + 1);

    for (i = 0; i < lenmess; i++)
    {
        if (EUSART2_is_tx_ready())
        {
            EUSART2_Write(arSendBuff2[i]);
            while (!EUSART2_is_tx_done()) NOP();
        }
    }
}

void WorkWithBlock1(void)
{ //команды с малины
    switch (arRecivBuff1[0])
    {
        case CMD_TEST:
            SendMessage1(ANS_OK, NULL, 0);
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
            SendMessage1(ANS_SERNUM, &iSerNum, sizeof (uint16_t));
            break;
        case CMD_GET_ID:
            ReadMyFlash();
            SendMessage1(ANS_ID, sId, sizeof (sId));
            break;
            //            case CMD_TEST:
            //            SendMessage1(ANS_OK, NULL, 0);
            //            break;            
        default:
            break;
    }
}

void WorkWithBlock2(void)
{ //ответы с терминала
    switch (arRecivBuff2[0])
    {
        case ANS_OK:
            //SendMessage2(ANS_OK, NULL, 0);
            break;
        case ANS_ERROR:
            //SendMessage2(ANS_OK, NULL, 0);
            break;
        case ANS_STATUS:
            //SendMessage2(ANS_OK, NULL, 0);
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

    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    //INTERRUPT_GlobalInterruptDisable();
    //INTERRUPT_PeripheralInterruptDisable();

    while (1)
    {
        if (IntrChanged.bIntrUsart1)
        {
            WorkWithBlock1();
            IntrChanged.bIntrUsart1 = false;
        }

        if (IntrChanged.bIntrUsart2)
        {
            WorkWithBlock2();
            IntrChanged.bIntrUsart2 = false;
        }
    }
}
/**
 End of File
 */
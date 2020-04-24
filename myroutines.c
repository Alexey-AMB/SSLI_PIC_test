/*
 * File:   myroutines.c
 * Author: Alexey
 * for SSLI_PIC
 * Created on 24 апреля 2020 г., 10:58
 */

//Format message from USART:
//start byte = 0A
//length data - length all message include CRC
//command
//-   d
//    a
//    t
//-   a
//CRC8 - for command and data

#include "mcc_generated_files/mcc.h"
#include "myroutines.h"

uint16_t BaseHEAddr = 0x0fdf;

uint8_t iRecived1 = 0;
uint8_t iExpectedLen1 = 0;
uint8_t rbyte1 = 0;

uint8_t iRecived2 = 0;
uint8_t iExpectedLen2 = 0;
uint8_t rbyte2 = 0;

void ReadMyFlash(void)
{
    // 0f80-0fff

    char i = 0;

    memset(sId, 0, sizeof (sId));
    iSerNum = 0;

    iSerNum = FLASH_ReadWord(BaseHEAddr);

    for (i = 0; i < 8; i++)
    {
        sId[i] = FLASH_ReadWord(BaseHEAddr + 2 + (i * 2));
    }
}

void WriteMyFlash(void)
{
    char i = 0;

    uint16_t wrBlockData[WRITE_FLASH_BLOCKSIZE];
    memset(wrBlockData, 0, sizeof (wrBlockData));
    memcpy(wrBlockData, &iSerNum, 2);

    for (i = 0; i < 16; i++)
    {
        memcpy(wrBlockData + 2 + i, sId, 1);
    }

    FLASH_WriteBlock(BaseHEAddr, wrBlockData);
}

void Usart1GetBlock(void)
{
    while ((eusart1RxCount > 0)&&(!IntrChanged.bIntrUsart1))
    {
        rbyte1 = EUSART1_Read();
        if (iRecived1 == 0)
        {
            if (rbyte1 != 0x0A) continue;
            else iRecived1++;
        }
        else
        {
            if (iRecived1 == 1)
            {
                iExpectedLen1 = rbyte1;
                memset(arRecivBuff1, 0, sizeof (arRecivBuff1));
                if (iExpectedLen1 > sizeof (arRecivBuff1))
                {
                    iRecived1 = 0;
                    iExpectedLen1 = 0;
                    //sendErr()
                    break;
                }
            }
            if ((iRecived1 > 1) && (iRecived1 < iExpectedLen1 - 1))
            {
                arRecivBuff1[iRecived1 - 2] = rbyte1;
            }
            if (iRecived1 >= iExpectedLen1)
            {
                if (GetCRC8(arRecivBuff1, iRecived1) == rbyte1)
                {
                    IntrChanged.bIntrUsart1 = true;
                    //sendOk()
                }
                else
                {
                    //error crc - sendErr()
                }
                iRecived1 = 0;
                iExpectedLen1 = 0;
                break;
            }
            iRecived1++;
        }
    }
}

void Usart2GetBlock(void)
{
    while ((eusart2RxCount > 0)&&(!IntrChanged.bIntrUsart2))
    {
        rbyte2 = EUSART2_Read();
        if (iRecived2 == 0)
        {
            if (rbyte2 != 0x0A) continue;
            else iRecived2++;
        }
        else
        {
            if (iRecived2 == 1)
            {
                iExpectedLen2 = rbyte2;
                memset(arRecivBuff2, 0, sizeof (arRecivBuff2));
                if (iExpectedLen2 > sizeof (arRecivBuff2))
                {
                    iRecived2 = 0;
                    iExpectedLen2 = 0;
                    //sendErr()
                    break;
                }
            }
            if ((iRecived2 > 1) && (iRecived2 < iExpectedLen2 - 1))
            {
                arRecivBuff2[iRecived2 - 2] = rbyte2;
            }
            if (iRecived2 >= iExpectedLen2)
            {
                if (GetCRC8(arRecivBuff2, iRecived2) == rbyte2)
                {
                    IntrChanged.bIntrUsart2 = true;
                    //sendOk()
                }
                else
                {
                    //error crc - sendErr()
                }
                iRecived2 = 0;
                iExpectedLen2 = 0;
                break;
            }
            iRecived2++;
        }
    }
}

uint8_t GetCRC8(uint8_t *buf, uint8_t lenbuf)
{
    uint8_t i;
    uint8_t crc = 0;

    for (i = 0; i < lenbuf; i++) crc += (uint8_t)*(buf + i);

    return crc;
}








/**
 End of File
 */
/* 
 * File:   
 * Author: Alexey
 * Comments:
 * Revision history: 0.1
 * for SSLI_PIC
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    DOWN_MODE = 0,
    SLEEP_MODE,
    WORK_MODE,
    REBOOT_MODE
} ScMode;

typedef struct {
    bool bIntrUsart1;
    bool bIntrUsart2;
} stInterrupt;

extern uint16_t iSerNum;
extern uint16_t sId[8]; //char[16]

extern uint8_t arRecivBuff1[20];
extern uint8_t arRecivBuff2[30];
extern stInterrupt IntrChanged;

void ReadMyFlash(void);
void WriteMyFlash(void);

void Usart1GetBlock(void);
void Usart2GetBlock(void);

uint8_t GetCRC8(uint8_t *buf, uint8_t lenbuf);





#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */


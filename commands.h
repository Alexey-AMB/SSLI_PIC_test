/* 
 * File:   
 * Author: Alexey
 * Comments:
 * Revision history: 
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
// ВАЖНО ! при переключении USBa и зарядки необходима пауза!

typedef enum {          //длинна данных, описание
    CMD_NONE = 0,       //0, не используется  
    CMD_TEST,           //0, ответ "ANS_OK"
    CMD_CHRG_EN,        //0, включить зарядку
    CMD_CHRG_DIS,       //0, выключить зарядку
    CMD_USBA_EN,        //0, включить USB
    CMD_USBA_DIS,       //0, выключить USB
    CMD_SC_SLEEP,       //0, отправить в сон, если включен, если уже сон или выключен - ничего
    CMD_SC_RUN,         //0, включить если уже не включен
    CMD_SC_DOWN,        //0, полностью выключить модуль - долго - 8 сек
    CMD_SC_REBOOT,      //0, выключить и включить - долго - 40 сек
    CMD_LED_R_ON,       //0, зажечь красный
    CMD_LED_R_OFF,      //0, погасить красный
    CMD_LED_G_ON,       //0, зажечь зеленый
    CMD_LED_G_OFF,      //0, погасить зеленый
    CMD_SOFT_UPD_PROGRESS, //0, сообщение, что прогр. верх. уровня начала обновление баз
    CMD_SOFT_UPD_DONE,  //0, сообщение, что прогр. верх. уровня завершила обновление баз
    CMD_GET_SERNUM,     //0, запрос сер. номера, ответ типа "ANS_SERNUM"
    CMD_GET_ID,         //0, запрос уникального номера, ответ типа "ANS_ID"
    CMD_GET_AKKVOLT,    //0, запрос напряжения аккумулятора  ответ "ANS_AKKVOLT"
    CMD_GET_STATUS,     //0, запрос текущего статуса, ответ типа "ANS_STATUS"
    CMD_SET_SERNUM,     //2, передача серийного номера, для проверки считать
    CMD_SET_ID,         //16, передача уникального ID,  для проверки считать
    CMDRAS_GET_STATUS   //0, запрос текущих статусов терминалов - только по USART1
} UsartCommand;

typedef enum {
    ANS_NONE = 100, //0, не используется
    ANS_OK,         //0
    ANS_ERROR,      //0
    ANS_SERNUM,     //2
    ANS_ID,         //16
    ANS_AKKVOLT,    //4
    ANS_STATUS,     //24 = AnsStatus
    ANS_ARSTAT      //5*AnsStatus
} UsartAnswer;

typedef struct {
    uint16_t SerNum;
    uint16_t sID[8];
    float fAkkV;
    uint8_t SC_mode; //0-down, 1-sleep, 2-work
    uint8_t UpdateState;
} AnsStatus;



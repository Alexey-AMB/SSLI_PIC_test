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
    CMD_SET_IP,         //2, передача последнего байта IP адресов станции и терминала
    CMDRAS_GET_STATUS,  //0, запрос текущих статусов терминалов - только по USART1
    CMDRAS_SET_IP,      //3, передача последнего байта IP адресов станции и терминала на указанный слот (слот, станция, терм) - только по USART1
    CMD_SET_UPDATES,    //1, передача статуса обмена обносвлениями статус: (0 - готов к передаче, 1 - передача завершена, 3 - передача завершена и перезагрузка)
    CMD_USB_OE_EN,      //0, включить канал USB
    CMD_USB_OE_DIS,     //0, полность выключить USB (и top и bottom)            
    CMDRAS_CHRG_EN,     //1, - параметр номер слота
    CMDRAS_CHRG_DIS,    //1, - параметр номер слота
    CMDRAS_USBA_EN,     //1, - параметр номер слота
    CMDRAS_USBA_DIS,    //1, - параметр номер слота
    CMDRAS_LED_R_ON,    //1, - параметр номер слота
    CMDRAS_LED_R_OFF,   //1, - параметр номер слота
    CMDRAS_LED_G_ON,    //1, - параметр номер слота
    CMDRAS_LED_G_OFF,   //1, - параметр номер слота
    CMDRAS_USBOE_EN,    //1, - параметр номер слота
    CMDRAS_USBOE_DIS,   //1, - параметр номер слота
    CMDRAS_SET_UPDATES, //2, передача статуса обмена обновлениями слот, статус: (0 - готов к передаче, 1 - передача завершена, 3 - передача завершена и перезагрузка)
    CMDRAS_SC_SLEEP,    //1, - параметр номер слота
    CMDRAS_SC_RUN,      //1, - параметр номер слота
    CMDRAS_SC_DOWN,     //1, - параметр номер слота
    CMDRAS_SC_REBOOT    //1, - параметр номер слота
} UsartCommand;

typedef enum {
    ANS_NONE = 100, //0, не используется
    ANS_OK,         //0
    ANS_ERROR,      //0
    ANS_SERNUM,     //2
    ANS_ID,         //16
    ANS_AKKVOLT,    //4
    ANS_STATUS,     //25 = AnsStatus
    ANS_ARSTAT,     //5*AnsStatus
    ANS_UPDATES     //1 (0 - готов к передаче, 1 - передача завершена, 3 - передача завершена и перезагрузка)
} UsartAnswer;

typedef struct {
    uint16_t SerNum;
    uint16_t sID[8];
    uint32_t uAkkmV;    //uint32 in mV
    uint8_t SC_mode; //0-down, 1-sleep, 2-work
    uint8_t UpdateState;
	uint8_t ChargeState;	//0-none, 1-in progress, 2-done
} AnsStatus;    //size = 25



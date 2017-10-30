#include "tp_ups.h"
#include "tpl_os.h"

#define APP_Task_read_button_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
  initBoard(BUTTON_NOIT);
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}
/* ************************************************** */
TASK(read_button)
{
TickType tick;

  if (readButton() == BUTTON_PRESSED) {
 
    if (GetAlarm(blink_blink, &tick)== E_OS_NOFUNC ){  /* <=> blink_blink == off */
    	SetEvent(init, ev_init);
    	
    //ledToggle(RED);  // DEBUG
    }
    else{
	SetEvent(final, ev_final);

    
     //   ledToggle(ORANGE);  // DEBUG
    }
  }
 
}
#define APP_Task_read_button_STOP_SEC_CODE
#include "tpl_memmap.h"
/* ************************************************** */
#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"
 
TASK(blink)
{
    ledToggle(BLUE);
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"
/* ************************************************** */
#define APP_Task_init_START_SEC_CODE
#include "tpl_memmap.h"
 
TASK(init)
{
	WaitEvent(ev_init);
	ClearEvent(ev_init);
 	ledOn(GREEN);
 	delay(500);
 	ledOff(GREEN);
 	delay(100);
 	SetRelAlarm(blink_blink,1,100);   // start alarm , set period 100ms
 	
 	ChainTask(final);
 
}
#define APP_Task_init_STOP_SEC_CODE
#include "tpl_memmap.h"
/* ************************************************** */
#define APP_Task_final_START_SEC_CODE
#include "tpl_memmap.h"
 
TASK(final)
{
	WaitEvent(ev_final);
	ClearEvent(ev_final);
 	CancelAlarm(blink_blink);  // stop alarm
     	ledOn(RED);
 	delay(500);
 	ledOff(RED);
  	delay(100);
  	ActivateTask(blink_blink);
  	
 	ChainTask(init);
}
#define APP_Task_final_STOP_SEC_CODE
#include "tpl_memmap.h"
/* ************************************************** */
#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * This is necessary for ST libraries
 */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
{
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


#include "tp_ups.h"
#include "tpl_os.h"
#define APP_Task_bgTask_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
  initBoard(BUTTON_NOIT);
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}
/* ************************************************** */
/* **** ********************************************** */
volatile int val = -10; //
volatile int activationCount = 0;
 
TASK(bgTask){
	while(1){
		val++;
			

	}
	TerminateTask();
}
#define APP_Task_bgTask_STOP_SEC_CODE
#include "tpl_memmap.h"
/* ************************************************** */
#define APP_Task_periodicTask_START_SEC_CODE
#include "tpl_memmap.h"
 
TASK(periodicTask)
{

    activationCount++;
    if(activationCount%2 == 0){
    	val ++;
    }
    else{
    	val--;
    }	TerminateTask();
}
#define APP_Task_periodicTask_STOP_SEC_CODE
#include "tpl_memmap.h"
/* ************************************************** */
#define APP_Task_displayTask_START_SEC_CODE
#include "tpl_memmap.h"
 
TASK(displayTask)
{
	ledOn(BLUE);
	if((val >= -1)&&(val <= 2)){
		ledOn(LED4);
		ledOff(LED5);    
	}
	else{
		ledOff(LED4);
		ledOn(LED5);
	}

	ledOff(BLUE);	TerminateTask();
}
#define APP_Task_displayTask_STOP_SEC_CODE
#include "tpl_memmap.h"
/* ************************************************** */

/*
 * This is necessary for ST libraries
 */
#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
{
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


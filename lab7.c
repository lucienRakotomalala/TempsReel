#include "tp_ups.h"
#include "tpl_os.h"
#define APP_Task_orange_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
  initBoard(BUTTON_NOIT);
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}
/* ************************************************** */
/* **** ********************************************** */
 
TASK(orange)
{
    ledToggle(ORANGE);
}
#define APP_Task_orange_STOP_SEC_CODE
#include "tpl_memmap.h"
/* ************************************************** */
#define APP_Task_green_START_SEC_CODE
#include "tpl_memmap.h"
 
TASK(green)
{
    ledToggle(GREEN);
}
#define APP_Task_green_STOP_SEC_CODE
#include "tpl_memmap.h"
/* ************************************************** */
#define APP_Task_blue_START_SEC_CODE
#include "tpl_memmap.h"
 
TASK(blue)
{
    ledToggle(BLUE);
}
#define APP_Task_blue_STOP_SEC_CODE
#include "tpl_memmap.h"
/* ************************************************** */
#define APP_Task_red_START_SEC_CODE
#include "tpl_memmap.h"
 
TASK(red)
{
    ledToggle(RED);
}
#define APP_Task_red_STOP_SEC_CODE
#include "tpl_memmap.h"
/* ************************************************** */

#define APP_ISR_buttonISR_START_SEC_CODE
#include "tpl_memmap.h"
ISR(buttonISR)
{
static int etat=0;

 
 	CancelAlarm(alarm_orange);
 	CancelAlarm(alarm_red);
 	CancelAlarm(alarm_blue);
 	CancelAlarm(alarm_green);
 	
    if (etat==0){  //sens horaire
     	SetRelAlarm(alarm_orange,1,500);  
    	SetRelAlarm(alarm_green,126,500);
    	SetRelAlarm(alarm_blue,251,500);
 	SetRelAlarm(alarm_red,376,500);
 	etat=1;
    }
    else{ // sens anti-horaire
	SetRelAlarm(alarm_red,1,500);  
    	SetRelAlarm(alarm_blue,126,500);
    	SetRelAlarm(alarm_green,251,500);
 	SetRelAlarm(alarm_orange,376,500);
 	etat=0;
    }

}
#define APP_ISR_buttonISR_STOP_SEC_CODE
#include "tpl_memmap.h"

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


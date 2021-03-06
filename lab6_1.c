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
    SetRelAlarm(blink_blink,1,100);   // start alarm , set period 100ms
    
    //ledToggle(RED);  // DEBUG
    }
    else{
    CancelAlarm(blink_blink);  // stop alarm
     //   ledToggle(ORANGE);  // DEBUG
    }
  }
	TerminateTask();
}
#define APP_Task_read_button_STOP_SEC_CODE
#include "tpl_memmap.h"
/* ************************************************** */
#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"
 
TASK(blink)
{
//  if (readButton() == BUTTON_PRESSED) {
    ledToggle(BLUE);
//  }
	TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
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


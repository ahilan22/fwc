/*==========================================================
Code by G V V Sharma
Feb 26, 2019,
Released under GNU/GPL
https://www.gnu.org/licenses/gpl-3.0.en.html
/*==========================================================
 *
 *    File   : main.c
 *    Purpose: main for Pygmy Decade Counter 
 *                                                          
 *=========================================================*/

#include "Fw_global_config.h"   // This defines application specific charactersitics

#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"
#include "RtosTask.h"

/*    Include the generic headers required for QORC */
#include "eoss3_hal_gpio.h"
#include "eoss3_hal_rtc.h"
#include "eoss3_hal_timer.h"
#include "eoss3_hal_fpga_usbserial.h"
#include "ql_time.h"
#include "s3x_clock_hal.h"
#include "s3x_clock.h"
#include "s3x_pi.h"
#include "dbg_uart.h"

#include "cli.h"


extern const struct cli_cmd_entry my_main_menu[];


const char *SOFTWARE_VERSION_STR;


/*
 * Global variable definition
 */


extern void qf_hardwareSetup();
static void nvic_init(void);
void PyHal_Set_GPIO(uint8_t gpionum, uint8_t gpioval);
void sevenseg(int a, int b, int c, int d, int e, int f, int g);
void disp(int num); 

int main(void)
{
    uint32_t i=0,j=0,k=0;
    SOFTWARE_VERSION_STR = "qorc-onion-apps/qf_hello-fpga-gpio-ctlr";
    
    qf_hardwareSetup();
    nvic_init();

    dbg_str("\n\n");
    dbg_str( "##########################\n");
    dbg_str( "Quicklogic QuickFeather FPGA GPIO CONTROLLER EXAMPLE\n");
    dbg_str( "SW Version: ");
    dbg_str( SOFTWARE_VERSION_STR );
    dbg_str( "\n" );
    dbg_str( __DATE__ " " __TIME__ "\n" );
    dbg_str( "##########################\n\n");

    dbg_str( "\n\nHello GPIO!!\n\n");	// <<<<<<<<<<<<<<<<<<<<<  Change me!

    CLI_start_task( my_main_menu );
	HAL_Delay_Init();

    //Seven Segment GPIO
while(1){
	disp(i);
	HAL_DelayUSec(1000000);    
	i++;
	if (i == 10)
		i = 0;
}

    /* Start the tasks and timer running. */
    vTaskStartScheduler();
    dbg_str("\n");

    while(1);
}

static void nvic_init(void)
 {
    // To initialize system, this interrupt should be triggered at main.
    // So, we will set its priority just before calling vTaskStartScheduler(), not the time of enabling each irq.
    NVIC_SetPriority(Ffe0_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
    NVIC_SetPriority(SpiMs_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
    NVIC_SetPriority(CfgDma_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
    NVIC_SetPriority(Uart_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
    NVIC_SetPriority(FbMsg_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
 }    

void sevenseg(int a, int b, int c, int d, int e, int f, int g)

{
    //Seven Segment GPIO
    PyHal_Set_GPIO(4,a);//a
    PyHal_Set_GPIO(5,b);//b
    PyHal_Set_GPIO(6,c);//c
    PyHal_Set_GPIO(7,d);//d
    PyHal_Set_GPIO(8,e);//e
    PyHal_Set_GPIO(10,f);//f
    PyHal_Set_GPIO(11,g);//g
}


void disp(int num)
{
switch(num)
{
	case 0:
	  sevenseg(0,0,0,0,0,0,1);
	break;
	case 1:
	  sevenseg(1,0,0,1,1,1,1);
	break;
	case 2:
	  sevenseg(0,0,1,0,0,1,0);
	break;
	case 3:
	  sevenseg(0,0,0,0,1,1,0);
	break;
	case 4:
	  sevenseg(1,0,0,1,1,0,0);
	break;
	case 5:
	  sevenseg(0,1,0,0,1,0,0);
	break;
	case 6:
	  sevenseg(0,1,0,0,0,0,0);
	break;
	case 7:
	  sevenseg(0,0,0,1,1,1,1);
	break;
	case 8:
	  sevenseg(0,0,0,0,0,0,0);
	break;
	case 9:
	  sevenseg(0,0,0,0,1,0,0);
	break;
	default:
	  sevenseg(0,1,1,0,0,0,0);
	break;
}
}

//needed for startup_EOSS3b.s asm file
void SystemInit(void)
{

}

//gpionum --> 0 --> 31 corresponding to the IO PADs
//gpioval --> 0 or 1
#define FGPIO_DIRECTION_REG (0x40024008)
#define FGPIO_OUTPUT_REG (0x40024004)

void PyHal_Set_GPIO(uint8_t gpionum, uint8_t gpioval)
{
    uint32_t tempscratch32;

    if (gpionum > 31)
        return;

    tempscratch32 = *(uint32_t*)(FGPIO_DIRECTION_REG);

    *(uint32_t*)(FGPIO_DIRECTION_REG) = tempscratch32 | (0x1 << gpionum);

    
    tempscratch32 = *(uint32_t*)(FGPIO_OUTPUT_REG);

    if(gpioval > 0)
    {
        *(uint32_t*)(FGPIO_OUTPUT_REG) = tempscratch32 | (0x1 << gpionum);
    }
    else
    {
        *(uint32_t*)(FGPIO_OUTPUT_REG) = tempscratch32 & ~(0x1 << gpionum);
    }    

    return;
}



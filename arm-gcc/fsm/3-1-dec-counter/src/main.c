/*==========================================================
Code by G V V Sharma
Apr 11, 2021,
Released under GNU/GPL
https://www.gnu.org/licenses/gpl-3.0.en.html
/*==========================================================
 *
 *    File   : main.c
 *    Purpose: main for Decade Counter using 7447 decoder and flip-flops
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


/*===========================================================
		pre-defintions
============================================================*/


extern const struct cli_cmd_entry my_main_menu[];

const char *SOFTWARE_VERSION_STR;


/*
 * Global variable definition
 */


extern void qf_hardwareSetup();
static void nvic_init(void);
#define GPIO_OUTPUT_MODE (1)
#define GPIO_INPUT_MODE (0)
void PyHal_GPIO_SetDir(uint8_t gpionum,uint8_t iomode);
int PyHal_GPIO_GetDir(uint8_t gpionum);
int PyHal_GPIO_Set(uint8_t gpionum, uint8_t gpioval);
int PyHal_GPIO_Get(uint8_t gpionum);


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

//needed for startup_EOSS3b.s asm file
void SystemInit(void)
{

}

//gpionum --> 0 --> 31 corresponding to the IO PADs
//gpioval --> 0 or 1
#define FGPIO_DIRECTION_REG (0x40024008)
#define FGPIO_OUTPUT_REG (0x40024004)
#define FGPIO_INPUT_REG (0x40024000)
//Set GPIO(=gpionum) Mode: Input(iomode = 0) or Output(iomode = 1)
//Before Set/Get GPIO value, the direction must be correctly set
void PyHal_GPIO_SetDir(uint8_t gpionum,uint8_t iomode)
{
    uint32_t tempscratch32;

    if (gpionum > 31)
        return;

    tempscratch32 = *(uint32_t*)(FGPIO_DIRECTION_REG);
    if (iomode)
        *(uint32_t*)(FGPIO_DIRECTION_REG) = tempscratch32 | (0x1 << gpionum);
    else
        *(uint32_t*)(FGPIO_DIRECTION_REG) = tempscratch32 & (~(0x1 << gpionum));

}


//Get current GPIO(=gpionum) Mode: Input(iomode = 0) or Output(iomode = 1)
int PyHal_GPIO_GetDir(uint8_t gpionum)
{
    uint32_t tempscratch32;
    int result = 0;

    if (gpionum > 31)
        return -1;

    tempscratch32 = *(uint32_t*)(FGPIO_DIRECTION_REG);

    result = ((tempscratch32 & (0x1 << gpionum)) ? GPIO_OUTPUT_MODE : GPIO_INPUT_MODE);

    return result;
}

//Set GPIO(=gpionum) to 0 or 1 (= gpioval)
//The direction must be set as Output for this GPIO already
//Return value = 0, success OR -1 if error.
int PyHal_GPIO_Set(uint8_t gpionum, uint8_t gpioval)
{
    uint32_t tempscratch32;

    if (gpionum > 31)
        return -1;

    tempscratch32 = *(uint32_t*)(FGPIO_DIRECTION_REG);

    //Setting Direction moved out as separate API, we will only check
    //*(uint32_t*)(FGPIO_DIRECTION_REG) = tempscratch32 | (0x1 << gpionum);
    if (!(tempscratch32 & (0x1 << gpionum)))
    {
        //Direction not Set to Output
        return -1;
    }
    
    tempscratch32 = *(uint32_t*)(FGPIO_OUTPUT_REG);

    if(gpioval > 0)
    {
        *(uint32_t*)(FGPIO_OUTPUT_REG) = tempscratch32 | (0x1 << gpionum);
    }
    else
    {
        *(uint32_t*)(FGPIO_OUTPUT_REG) = tempscratch32 & ~(0x1 << gpionum);
    }    

    return 0;
}
//Get GPIO(=gpionum): 0 or 1 returned (or in erros -1)
//The direction must be set as Input for this GPIO already
int PyHal_GPIO_Get(uint8_t gpionum)
{
    uint32_t tempscratch32;
    uint32_t gpioval_input;

    if (gpionum > 31)
        return -1;

    tempscratch32 = *(uint32_t*)(FGPIO_INPUT_REG);
    gpioval_input = (tempscratch32 >> gpionum) & 0x1;

    return ((int)gpioval_input);
}

/*=========================================================
		the code
============================================================*/

#define pinW	28
#define pinX	23
#define pinY	31
#define pinZ	29

#define pinD	4
#define pinC	6
#define pinB	8
#define pinA	10

#define clk	5

void disp_7447(int D,int C,int B, int A)
{
    PyHal_GPIO_Set(pinD,D); //D
    PyHal_GPIO_Set(pinC,C); //C
    PyHal_GPIO_Set(pinB,B); //B
	PyHal_GPIO_Set(pinA,A); //A
}

void setup(void)
{
    //Set GPIO direction
    PyHal_GPIO_SetDir(pinD,1); //A
    PyHal_GPIO_SetDir(pinC,1); //D
    PyHal_GPIO_SetDir(pinB,1); //C
    PyHal_GPIO_SetDir(pinA,1); //B
    PyHal_GPIO_SetDir(clk,1); //clock
}

int main(void)
{
    uint32_t i=0,j=0,k=0;
    uint32_t Z=0,Y=0,X=0,W=0;
    uint32_t D=0,C=0,B=0,A=0;

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
    
	PyHal_GPIO_SetDir(pinW,0); //Input
	PyHal_GPIO_SetDir(pinX,0); //Input
	PyHal_GPIO_SetDir(pinY,0); //Input
	PyHal_GPIO_SetDir(pinZ,0); //Input
	setup(); //sets output pins, clock

while(1)
{
	PyHal_GPIO_Set(clk,1);

	Z = PyHal_GPIO_Get(pinZ);  
	Y = PyHal_GPIO_Get(pinY);  
	X = PyHal_GPIO_Get(pinX);  
	W = PyHal_GPIO_Get(pinW);  
	
	//Incrementing W,X,Y,Z
	D = (W&X&Y&(!Z))|((!W)&(!X)&(!Y)&Z);//Boolean function for D
	C=((!Z)&(!Y)&(X)&W)|((!Z)&(Y)&!X&(!W))|((!Z)&Y&(!X)&W)|((!Z)&Y&X&(!W));
	B=((!Z)&(!Y)&!X&W)|((!Z)&!Y&(X)&(!W))|((!Z)&Y&(!X)&W)|((!Z)&Y&X&(!W));
	A = ((!W)&(!X)&(!Y)&(!Z))|((!W)&(X)&(!Y)&(!Z))|((!W)&(!X)&Y&(!Z))|((!W)&X&Y&(!Z))|((!W)&(!X)&(!Y)&(Z));
	
	disp_7447(D,C,B,A);

	PyHal_GPIO_Set(clk,0);
	HAL_DelayUSec(1000000);
}

    /* Start the tasks and timer running. */
    vTaskStartScheduler();
    dbg_str("\n");

    while(1);
}

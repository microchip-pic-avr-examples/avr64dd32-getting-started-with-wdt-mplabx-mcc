 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2022] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include <avr/wdt.h>
#include <util/delay.h>

#define BUTTON_PRESSED         !(PORTF.IN & (PIN6_bm))
#define LONG_DELAY             1000
#define SMALL_DELAY            200  

/*
    Main application
*/

static void My_Application();
static void LED_Blink(uint8_t contor);

int main(void)
{
    SYSTEM_Initialize();
    
    LED_Blink(3);
    
    while (1)
    {
        /* Simulate an user application. */
        My_Application();
        
        /* Periodic LED blinking at ~1s shows normal functioning of the application. */
        LED_Blink(1);
        
        /* Clear WDT periodically.
         * Failing to this in time, will cause it to reset the microcontroller.
         */
        wdt_reset();
    }
}

static void My_Application()
{
    /* Simulate the user application doing something. */
    _delay_ms(LONG_DELAY);

    while(BUTTON_PRESSED)
    {
        /*
         * The purpose of this is to make the program stop here, simulating a 
         * malfunction, that will cause it to miss th reset the WDT in time. 
         * The WDT will in turn reset the microcontroller, this is noticeable
         * by the LED blinking three time.
         */
        ;
    }
}

static void LED_Blink(uint8_t contor)
{
    while(contor--)
    {
        LED_SetLow();
        _delay_ms(SMALL_DELAY);
        
        LED_SetHigh();
        _delay_ms(SMALL_DELAY); 
    }
}
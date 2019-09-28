/**
 * Welcome to Embedded Software Tutorial, part 1.
 * 
 * This short program makes the green LED LD2, located on pin A5, turn on.
 * 
 * Task 0: If you are not sure how hexadecimal or bitshifting works, ask Software Lead for explanation
 * 
 * Task 1: Compile and Flash this program on Keil uVision. Observe that the green LED on the
 *          nucleo-64 development board lights up.
 * Task 2: Open the STM32 nucleo-64 user manual (69 pages). Search the datasheet to find which pin 
 *          is connected to the green LED on the nucleo-64 board. Confirm the answer with the Software Lead.
 * Task 3: Open the STM32 Reference Manual (1134 pages). Attempt to deduce what each line of code does.
 *          Comment what you think each line of code does, and confirm later with the Software Lead.
 * Task 4: Looking at the STM32 Reference Manual, see how you can set a pin to LOW. Write a function in your
 *          code to set up a short delay (Don't worry if it is crude - we will show you a better way soon.)
 *          Set your code to make the green LED blink.
 * Task 5: Open the STM32 nucleo-64 user manual. Find out which pin corresponds to a button on the nucleo-64.
 * 
 * Task 6 (BOSS): How can you write a program to toggle the light when the button is pressed? 
 *                  (Don't be afraid to ask for help - this is very difficult for someone new to the STM32,
 *                   but learning how this is done is a major milestone)
 */

#include "stm32f10x.h"

int main(void)
{

	RCC->APB2ENR = 0x1 << 2;

    GPIOA->CRL &= ~(0xF << 20);     //Hint: Look at the reset value in the datasheet.
    GPIOA->CRL |= 0x3 << 20;

    GPIOA->BSRR = 0x1 << 5;
    
}
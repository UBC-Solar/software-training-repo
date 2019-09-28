/**
 * Welcome to Embedded Software Tutorial, part 3.
 * 
 * This program is meant to explore the limitations of using crude loop-based timing for
 *  time-critical inputs, and how this problem can be averted using external interrupts.
 * 
 * Task 1: Remember doing the tutorial on the first day workshop? Remember how the button keeps
 *          failing to set the LED to turn on when you press it really quickly? Go back to your 
 *          previous code, and come up with a plausible explanation as to why the button sometimes
 *          does not work.
 * Task 2: On Keil uVision, Compile and Flash this program. Press the blue button, and appreciate
 *          how the everything happens promptly.
 * Task 3: Endure an explanation from the Software Lead on how external interrupts work, and a bit
 *          about NVIC tables.
 * 
 */
 
#include "stm32f10x.h"
 
void EXTI15_10_IRQHandler(void)
{
	if ( (((EXTI->PR) >> 13) & 0x1) )
	{
		GPIOA->BSRR = 0x1 << 5;
		
	}
	
}

int main(void)
{	
	
	RCC->APB2ENR |= 0x1 << 2;
	GPIOA->CRL &= 0;
	GPIOA->CRL |= 0x3 << 20;
	
	RCC->APB2ENR |= 0x1 << 4;
	GPIOC->CRH &= 0;
	GPIOC->CRH |= 0x8 << 20;
	
	RCC->APB2ENR |= 0x1;
	AFIO->EXTICR[3] = 0x2 << 4;
	
	EXTI->IMR |= 0x1 << 13;
	EXTI->RTSR |= 0x1 << 13;
	
	NVIC_EnableIRQ(EXTI15_10_IRQn);
	
	while(1)
	{
		//do nothing
	}
}
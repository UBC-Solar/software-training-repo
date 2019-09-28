/**
 * Welcome to Embedded Software Tutorial, part 2.
 * 
 * This program outputs text to a virtual serial port on your computer,
 *      through the STM32's USART2 peripheral.
 * 
 * Task 1: Ensure that you have PuTTy installed on your device
 * Task 2: On Keil uVision, Compile and Flash this program. Open PuTTy, Connection >> Serial.
 *          Go to your task manager, and find out which COM port the nucleo-64 board is connected to.
 *          Input said COM port, ensure that the baud rate is set to 9600, and open the virtual serial port.
 *          If all goes well, you should see legible text appear on the screen.
 * Task 3: Repeat Task 2, but set the baud rate to a different value. What happens?
 * 
 */

#include "stm32f10x.h"


void VirtualComInit(void);
void SendChar(char c);
void SendString(char* str);
void SendInt(uint32_t i);
void SendLine(void);

int main(void)
{

    VirtualComInit();

    while(1)
    {
        SendString("The STM32 says hello.");
        SendLine();
    }

}

/**
 * Initializes virtual com.
 */
void VirtualComInit(void)
{
	// Enable GPIOA clock, AFIO
	RCC->APB2ENR |= 0x5UL;
	GPIOA->CRL &= ~(0xFF00UL);
	GPIOA->CRL |= 0x4B00UL;
	
	// Enable USART2 clock
	RCC->APB1ENR |= (0x1UL << 17);
	USART2->CR2 = 0;
	USART2->CR3 = 0;
	USART2->CR1 |= 0xC;
	
	// By Default, set baudrate to 9600
	USART2->BRR = 0xEA6UL;
	
	// Enable USART2
	USART2->CR1 |= 0x1 << 13;
	
}

/**
 * Sends ASCII character through USART. 
 *
 * @Param c: transmitted character
 */
void SendChar(char c)
{
	// Write data to data register
	USART2->DR = 0xFF & ((uint8_t) c);
	
	// Poll until character is transmitted
	while (!((USART2->SR >> 7) & 0x1));
	
}

/**
 * Sends string through USART.
 *
 * @Param str: transmitted string
 */
 void SendString(char* str)
 {
	int i;
	
	// Send each character separately
	for (i = 0; str[i] != '\0'; i++)
	{
		SendChar(str[i]);
	}
 }

/**
 * Sends 32-bit unsigned integer through USART (with padded zeros)
 * Number will be represented in hexadecimal.
 * 
 * @Param i: transmitted 32-bit unsigned integer
 */
void SendInt(uint32_t i)
{
	int index;
	
	SendChar(0x30);
	SendChar(0x58);
	
	for (index = 7; index >= 0; index--)
	{
		// Divide integer into half-bytes and send them separately
		SendChar("0123456789ABCDEF"[(i >> (index*4)) & 0xFUL]);
	}
}
 
 /**
 * Sends a new line through USART
 */
void SendLine(void)
 {
	 SendChar(0xA); // Sends a line break
	 SendChar(0xD); // Moves cursor back to start of line
 }

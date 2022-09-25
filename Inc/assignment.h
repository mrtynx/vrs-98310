/*
 * assignment.h
 *
 *  Created on: 27. 9. 2020
 *      Author: Stancoj
 */

#ifndef ASSIGNMENT_H_
#define ASSIGNMENT_H_

/**
 * 		This header file provides macros to the MCU's registers required for this assignment.
 * 		Your task is to provide their actual implementation so you can use them in application in "main.c"
 * 		and make your "LED blink" application code readable and great again!
 */

/* General purpose input output port A macros */
//GPIOA peripheral base address
#define	GPIOA_BASE_ADDR			(uint32_t)(0x48000000U)
//MODER register
#define	GPIOA_MODER_REG			*(uint32_t *)(GPIOA_BASE_ADDR + 0x00U)
//OTYPER register
#define	GPIOA_OTYPER_REG		*(uint32_t *)(GPIOA_BASE_ADDR + 0x04U)
//OSPEEDER register
#define GPIOA_OSPEEDER_REG		*(uint32_t *)(GPIOA_BASE_ADDR + 0x08U)
//PUPDR register
#define GPIOA_PUPDR_REG			*(uint32_t *)(GPIOA_BASE_ADDR + 0x0CU)
//IDR register
#define GPIOA_IDR_REG			*(uint32_t *)(GPIOA_BASE_ADDR + 0x10U)
//ODR register
#define GPIOA_ODR_REG			*(uint32_t *)(GPIOA_BASE_ADDR + 0x14U)
//BSRR register
#define GPIOA_BSRR_REG			*(uint32_t *)(GPIOA_BASE_ADDR + 0x18U)
//BRR register
#define GPIOA_BRR_REG			*(uint32_t *)(GPIOA_BASE_ADDR + 0x28U)

/*Reset clock control register macros */
//RCC base address
#define	RCC_BASE_ADDR			(uint32_t)(0x40021000U)
//AHBEN register
#define	RCC_AHBENR_REG			*(uint32_t *)(RCC_BASE_ADDR + 0x14U)



/* LED and button macros */
#define LED_ON					*((volatile uint32_t *)((uint32_t)(GPIOA_BSRR_REG)))|= (1 << 4)
#define LED_OFF					*((volatile uint32_t *)((uint32_t)(GPIOA_BRR_REG)))|= (1 << 4)

#define BUTTON_GET_STATE		(*((volatile uint32_t *)((uint32_t)(GPIOA_IDR_REG))) & (1 << 6))


#endif /* ASSIGNMENT_H_ */

/*
Otazky na cviciaceho:

1. Preco v main branchi je RCC_AHBENR (r.41) definovany ako *((volatile uint32_t *)..
2. Preco v main branchi je RCC_AHBENR offset adresy zapisany ako 0x000..14 a nie iba 0x14
   a preco sa v main pri enable clock zapisuje na resetovaciu adresu 
3. Ci mozem resetovat aj cez BSRR, alebo vyhradne cez BRR a preco reset cez BRR je dany OR-om, resp ci sa BSRR da resetovat AND-om
4. Ci vypracovavat jednotlive zadania do separatneho repo, alebo staci jedno repo oddelene zlozkami


*/
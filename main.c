#include <stdint.h>

int main(void)
{
	// Enable Clock GPIOA 	(RCC->AHB1ENR)
	RCC->AHB1ENR |= 1;
	// PA5 Output			(GPIOA->MODER)
	uint32_t * ptr_GPIOA_ODR = (uint32_t *) 0x40020014;

	while(1){
		for(uint32_t i = 0 ; i<100000; i++);
		// Toggle PA5		(GPIOA->ODR)
		(*ptr_GPIOA_ODR) ^= (1<<5);
	}
}

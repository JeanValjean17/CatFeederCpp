#include <cstdint>
#include <algorithm>
#include "startup.hpp"
#include <array>

using irqPointer = std::uintptr_t;

extern "C" void DefaultHandler();

#pragma region ISR
//TODO: Move IRS to own file and change naming format

void NMIHandler()__attribute__((weak, alias("DefaultHandler")));
void HardFaultHandler()__attribute__((weak, alias("DefaultHandler")));
void SVCHandler()__attribute__((weak, alias("DefaultHandler")));
void PendSVHandler()__attribute__((weak, alias("DefaultHandler")));
void SysTickHandler()__attribute__((weak, alias("DefaultHandler")));


void WWDG_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void PVD_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void RTC_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void FLASH_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void RCC_CRS_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void EXTI0_1_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void EXTI2_3_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void EXTI4_15_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void TSC_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void DMA1_Channel1_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void DMA1_Channel2_3_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void DMA1_Channel4_5_6_7_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void ADC1_COMP_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void LPTIM1_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void USART4_5_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void TIM2_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void TIM3_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void TIM6_DAC_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void TIM7_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void TIM21_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void I2C3_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void TIM22_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void I2C1_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void I2C2_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void SPI1_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void SPI2_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void USART1_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void USART2_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void RNG_LPUART1_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void LCD_IRQHandler()__attribute__((weak, alias("DefaultHandler")));
void USB_IRQHandler()__attribute__((weak, alias("DefaultHandler")));



/*
Use functors?

or this

template<typename Func>
void executeFunction(Func f) {
    f();
}


Func would be our Interrupt coming from the peripherals and the 
execute function is the extern functiond linked to the interrupt vector 
*/
// template<typename InterruptFunc>
// constexpr irqPointer irq_handler(InterruptFunc func)
// {
//     return reinterpret_cast<irqPointer>(func);
// }


/*
    Create the InterruptHanlder declarations here
 */

const std::array<uint32_t, 48> isrVectors __attribute__((section(".isr_vector"))) = {
    SRAM_END,
    (uint32_t)ResetHandler,
    (uint32_t)NMIHandler,
    (uint32_t)HardFaultHandler,
    0, 
    0,
    0,
    0,
    0,
    0,
    0,
    (uint32_t)SVCHandler,
    0,
    0,
    (uint32_t)PendSVHandler,
    (uint32_t)SysTickHandler,
    (uint32_t)WWDG_IRQHandler,
    (uint32_t)PVD_IRQHandler,
    (uint32_t)RTC_IRQHandler,
    (uint32_t)FLASH_IRQHandler,
    (uint32_t)RCC_CRS_IRQHandler,
    (uint32_t)EXTI0_1_IRQHandler,
    (uint32_t)EXTI2_3_IRQHandler,
    (uint32_t)EXTI4_15_IRQHandler,
    (uint32_t)TSC_IRQHandler,
    (uint32_t)DMA1_Channel1_IRQHandler,
    (uint32_t)DMA1_Channel2_3_IRQHandler,
    (uint32_t)DMA1_Channel4_5_6_7_IRQHandler,
    (uint32_t)ADC1_COMP_IRQHandler,
    (uint32_t)LPTIM1_IRQHandler,
    (uint32_t)USART4_5_IRQHandler,
    (uint32_t)TIM2_IRQHandler,
    (uint32_t)TIM3_IRQHandler,
    (uint32_t)TIM6_DAC_IRQHandler,
    (uint32_t)TIM7_IRQHandler,
    0,
    (uint32_t)TIM21_IRQHandler,
    (uint32_t)I2C3_IRQHandler,
    (uint32_t)TIM22_IRQHandler,
    (uint32_t)I2C1_IRQHandler,
    (uint32_t)I2C2_IRQHandler,
    (uint32_t)SPI1_IRQHandler,
    (uint32_t)SPI2_IRQHandler,
    (uint32_t)USART1_IRQHandler,
    (uint32_t)USART2_IRQHandler,
    (uint32_t)RNG_LPUART1_IRQHandler,
    (uint32_t)LCD_IRQHandler,
    (uint32_t)USB_IRQHandler

};

// struct interruptVectors
// {
//     const irqPointer *stackPointer = &SRAM_END;
//     const irqPointer resetHandler = irq_handler(ResetHandler);
// };

// const volatile __attribute__((section(".isr_vector")))
// interruptVectors vectorTable{};


#pragma endregion

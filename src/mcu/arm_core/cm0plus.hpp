#include <cstdint>
#include "reg.hpp"
#include <span>

namespace core_m0_plus
{
    using pheripheral_addr = std::uintptr_t;

    constexpr pheripheral_addr scs_base = 0xE000E000;
    constexpr pheripheral_addr systick_base = scs_base + 0x0010;
    constexpr pheripheral_addr nvic_base = scs_base + 0x0100;
    constexpr pheripheral_addr scb_base = scs_base + 0x0D00;
    constexpr pheripheral_addr mpu_base = scs_base + 0x0D90;

    using namespace hal;


    namespace scb
    {
        // SCB Registers
        reg_ro cpu_id{scb_base + 0x00};
        reg icsr(scb_base + 0x04);
        reg vtor(scb_base + 0x08);
        reg aircr(scb_base + 0x0C);
        reg scr(scb_base + 0x10);
        reg_ro ccr(scb_base + 0x14);
        reg shpr2(scb_base + 0x1C);
        reg shpr3(scb_base + 0x20);
    }

    namespace stk
    {
        reg csr{systick_base};
        reg rvr{systick_base + 0x04};
        reg cvr{systick_base + 0x08};
        reg_ro calib{systick_base + 0x0C};

    } // namespace stk

    namespace mpu
    {
        reg_ro type{mpu_base};
        reg ctrl{mpu_base + 0x04};
        reg rnr{mpu_base + 0x08};
        reg rbar{mpu_base + 0x0C};
        reg rasr{mpu_base + 0x10};
    }

    namespace nvic
    {
        reg iser{nvic_base};
        reg icer{nvic_base + 0x080};
        reg ispr{nvic_base + 0x100};
        reg icpr{nvic_base + 0x180};
        

        // reg ipr0 {nvic_base + 0x300};
        // reg ipr1 {nvic_base + 0x304}; //Array?
    } // namespace nvic

}

#include <cstdint>
#include "cm0plus.hpp"


int main()
{
    volatile std::uint32_t cpu_id = core_m0_plus::scb::cpu_id.read();       

    while (true)
    {
    }
    return 0;
}

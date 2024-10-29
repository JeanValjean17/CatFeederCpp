#include <cstdint>
#include <algorithm>


extern std::uintptr_t _etext;

//Data Section
extern std::uintptr_t _sdata;
extern std::uintptr_t _edata;

extern std::uintptr_t _sbss;
extern std::uintptr_t _ebss;

extern std::uintptr_t _estack;
extern std::uintptr_t _sidata;

constexpr const std::uintptr_t SRAM_START = 0x20000000;
constexpr const std::uintptr_t SRAM_SIZE =  (20UL * 1024);
constexpr const std::uintptr_t SRAM_END = SRAM_START + SRAM_SIZE;



extern int main();

extern "C"{
    void ResetHandler();    
    void __libc_init_array();
}

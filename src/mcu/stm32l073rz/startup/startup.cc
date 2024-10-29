#include "startup.hpp"



void ResetHandler()
{
    //1. Copy .data section to SRAM
    uint32_t sizeDataSeciton = (uint32_t)&_edata - (uint32_t)&_sdata;
    

    std::copy(&_sidata, &_sidata + sizeDataSeciton, &_sdata);


    //2. Set .bss section to zero
    std::fill(&_sbss, &_ebss, 0);
    
    //call libc and main
    __libc_init_array();

    main();
    while (1)
    {
        
    }
}

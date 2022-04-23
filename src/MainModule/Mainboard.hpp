#ifndef Mainboard_hpp
#define Mainboard_hpp

#include "CPU.hpp"
#include "RAM.hpp"
#include "Memory.hpp"


namespace MainModule {
    class Mainboard {
        CPU* cpu;
        RAM* ram;
        Memory* memory;
        Memory* external_memory;

    public:
        Mainboard();
        ~Mainboard();

        void putCPU(CPU& cpu);
        void putRAM(RAM& ram);
        void putMemory(Memory& memory);
        void putExternalMemory(Memory& external_memory);
    };
}

#endif
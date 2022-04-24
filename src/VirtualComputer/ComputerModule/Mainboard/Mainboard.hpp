#ifndef Mainboard_hpp
#define Mainboard_hpp

#include "../CPU/CPU.hpp"
#include "../Memory/RAM.hpp"
#include "../Memory/Memory.hpp"


namespace ComputerModule {
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
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

        void plugCPU(CPU* cpu);
        void plugRAM(RAM* ram);
        void plugMemory(Memory* memory);
        void plugExternalMemory(Memory* external_memory);

        bool isRunnable() const;

        void playProgram(std::string program_title);

    private: 
        void loadProgramIntoRAM(std::string program_title);
        bool isOnRAM(std::string program_title) const;
    };
}

#endif
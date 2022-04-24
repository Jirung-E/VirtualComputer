#ifndef Computer_hpp
#define Computer_hpp

#include "ComputerModules.hpp"


namespace ComputerModule {
    class Computer {
        private: ComputerModule::CPU cpu;
        private: ComputerModule::Mainboard mainboard;
        private: ComputerModule::RAM ram;
        private: ComputerModule::Memory main_memory;
        private: ComputerModule::Memory external_memory;
    public:
        Computer();
    };
}

#endif
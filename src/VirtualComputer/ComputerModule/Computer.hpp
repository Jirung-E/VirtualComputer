#ifndef Computer_hpp
#define Computer_hpp

#include "ComputerModules.hpp"


namespace ComputerModule {
    class Computer {
        private: bool power;
        private: ComputerModule::CPU* cpu;
        private: ComputerModule::Mainboard* mainboard;
        private: ComputerModule::RAM* ram;
        private: ComputerModule::Memory* main_memory;
        
    public:
        Computer();
        ~Computer();
        
    public:
        bool isOn() const;
        
        void powerOn();
        void powerOff();
        
        void install(Program* program);
        void playProgram(std::string title);
        
        void doSomething();
    
    private:
        bool on() const;
        bool off() const;
    };
}

#endif
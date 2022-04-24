#ifndef User_hpp
#define User_hpp

#include <string>

#include "../ComputerModule/ComputerModules.hpp"


namespace UserModule {
    class User {
        private: std::string name;

        private: ComputerModule::CPU cpu;
        private: ComputerModule::Mainboard mainboard;
        private: ComputerModule::RAM ram;
        private: ComputerModule::Memory main_memory;
        private: ComputerModule::Memory external_memory;

    public:
        User(std::string name);
        ~User();
    };
}

#endif
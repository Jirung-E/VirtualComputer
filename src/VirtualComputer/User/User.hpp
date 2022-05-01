#ifndef User_hpp
#define User_hpp

#include <string>

#include "../ComputerModule/Computer.hpp"


namespace UserModule {
    class User {
        private: const std::string name;
        private: ComputerModule::Computer* pc;

    public:
        User(std::string name);
        ~User();
        
    public:
        void say(std::string dialogue) const;
        
        void setComputer(ComputerModule::Computer* computer);
        void turnOnTheComputer();
        void turnOffTheComputer();
        bool haveComputer() const;
        
        ComputerModule::Computer* computer();
    };
}

#endif
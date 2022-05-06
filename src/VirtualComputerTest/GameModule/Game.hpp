#ifndef Game_hpp
#define Game_hpp

#include "../../VirtualComputer/ComputerModule/Program/Program.hpp"

#include "GameModules.hpp"


namespace GameModule {
    class Game : public ComputerModule::Program {
        protected: Canvas canvas;
        
    public:
        Game(std::string title);
        ~Game();
        
    private:
        
    
    public:
        
    };
}

#endif
#ifndef Game_hpp
#define Game_hpp

#include "../MainModule/Program.hpp"


class Game : public MainModule::Program {
public:
    Game(std::string title);

    void play();
    void exit();
};

#endif
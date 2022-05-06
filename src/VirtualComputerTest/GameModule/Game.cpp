#include "Game.hpp"

using namespace std;
using namespace GameModule;


Game::Game(string title) : Program { title }, canvas { } {
    canvas.clearTo(' ');
}

Game::~Game() {
    
}
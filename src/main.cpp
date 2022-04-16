#include "TestModule/Test.hpp"
#include "Plugin/Game.hpp"
#include "MainModule/CPU.hpp"
#include "Utils/Util.hpp"

using namespace TestModule;
using namespace MainModule;
using namespace Utils;


void Play() {
    Game game { "ng" };
    game.play(); 
    game.exit();
}

int main() {
	Test t;
    //t.startTestAndShowResult();
    
    CPU cpu;
    cpu.push(Play);
    
    sleep(1321);
}
#include "TestModule/Test.hpp"
#include "Plugin/Game.hpp"
#include "MainModule/CPU.hpp"
#include "Utils/Util.hpp"
#include "MainModule/Mainboard.hpp"

using namespace TestModule;
using namespace MainModule;
using namespace Utils;


void Play() {
    Game game { "ng" };
    game.play(); 
    game.exit();
}

void MainBoardTest() {
    Game g { "temp_game" };
    
    CPU quadcore_cpu;
    RAM ram_8;
    Memory ssd { 16 };
    Memory sdcard { 16 };
    Mainboard main_board;
    main_board.putCPU(quadcore_cpu);
    main_board.putRAM(ram_8);
    main_board.putMemory(ssd);
    main_board.putExternalMemory(sdcard);
    
    ssd.push(&g);
    
    println(toString(ssd.getPercentOfMemoryIsFilled()));
}

int main() {
	Test t;
    //t.startTestAndShowResult();
    
    CPU cpu;
    cpu.push(Play);
    
    sleep(1321);
    
    MainBoardTest();
}
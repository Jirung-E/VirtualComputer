#include "VirtualComputer/Plugin/Game.hpp"
#include "VirtualComputer/MainModule/CPU.hpp"
#include "VirtualComputer/Utils/Util.hpp"
#include "VirtualComputer/MainModule/Mainboard.hpp"

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
    
    println(toString(ssd.percentageOfMemoryFilled()));
	
	ssd.pop("temp_game");
	
	println(toString(ssd.percentageOfMemoryFilled()));
}

int main() {
    CPU cpu;
    cpu.push(Play);
    
    sleep(1321);
    
    MainBoardTest();
}
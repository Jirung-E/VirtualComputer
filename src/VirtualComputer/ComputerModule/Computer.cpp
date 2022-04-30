#include "Computer.hpp"

using namespace ComputerModule;


Computer::Computer() : power { false }, cpu { new CPU(4) }, mainboard { new Mainboard() }, ram { new RAM(4) }, main_memory { new Memory(16) } {
    mainboard->plugCPU(cpu);
    mainboard->plugRAM(ram);
    mainboard->plugMemory(main_memory);
}

Computer::~Computer() {
    
}


void Computer::powerOn() {
    
}

void Computer::powerOff() {
    
}
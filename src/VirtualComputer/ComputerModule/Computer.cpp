#include "Computer.hpp"

#include "../Utils/Utils.hpp"

using namespace ComputerModule;
using namespace Utils;


Computer::Computer() : power { false }, cpu { new CPU(4) }, mainboard { new Mainboard() }, ram { new RAM(4) }, main_memory { new Memory(16) } {
    mainboard->plugCPU(cpu);
    mainboard->plugRAM(ram);
    mainboard->plugMemory(main_memory);
}

Computer::~Computer() {
    
}


void Computer::powerOn() {
    println("---------------------------------------------------");
    print("Booting");
    for(int i=0; i<5; ++i) {
        print(".");
        sleep(1000);
    }
    println("");
    println(" - - - - - - - - - - - - - - - - - - - - - - - - - ");
    println("Computer: Hello, User!\n");
}

void Computer::powerOff() {
    println("\nComputer: Bye, User!");
    println("---------------------------------------------------");
    println("");
}

void Computer::doSomething() {
    println("안녕 친구들");
    println("안녕 뽀로로");
    println("Hello friends!");
    println("Hello Pororo!");
}
#include "Computer.hpp"

#include "../Utils/Utils.hpp"

using namespace std;
using namespace ComputerModule;
using namespace Utils;


Computer::Computer() : power { false }, cpu { new CPU(4) }, mainboard { new Mainboard() }, ram { new RAM(4) }, main_memory { new Memory(16) } {
    mainboard->plugCPU(cpu);
    mainboard->plugRAM(ram);
    mainboard->plugMemory(main_memory);
}

Computer::~Computer() {
    
}


bool Computer::isOn() const {
    return power;
}

void Computer::powerOn() {
    if(isOn()) {
        return;
    }
    power = on();
    println("---------------------------------------------------");
    println("Booting...");
    for(int i=0; i<5; ++i) {
        //sleep(1000);
        println(".");
    }
    //sleep(1500);
    println("");
    println(" - - - - - - - - - - - - - - - - - - - - - - - - - ");
    //sleep(1000);
    println("Computer: Hello, User!\n");
    //sleep(1000);
}

void Computer::powerOff() {
    if(!isOn()) {
        return;
    }
    if(cpu != nullptr) {
        while(cpu->isRunning()) {
            continue;
        }
    }
    println("\nComputer: Bye, User!");
    //sleep(1000);
    println("---------------------------------------------------");
    power = off();
    println("");
    //sleep(2000);
}

void Computer::install(Program* program) {
    if(!isOn()) {
        return;
    }
    main_memory->push(program);
}

void Computer::playProgram(string title) {
    if(!isOn()) {
        return;
    }
    mainboard->playProgram(title);
}

void Computer::doSomething() {
    if(!isOn()) {
        return;
    }
    println("안녕 친구들");
    sleep(2000);
    println("안녕 뽀로로");
    sleep(2000);
    println("Hello friends!");
    sleep(2000);
    println("Hello Pororo!");
    sleep(2000);
}


bool Computer::on() const {
    return true;
}

bool Computer::off() const {
    return false;
}
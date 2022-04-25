#include "Mainboard.hpp"

using namespace std;
using namespace ComputerModule;


Mainboard::Mainboard() {

}

Mainboard::~Mainboard() {

}


void Mainboard::plugCPU(CPU& cpu) {
    this->cpu = &cpu;
}

void Mainboard::plugRAM(RAM& ram) {
    this->ram = &ram;
}

void Mainboard::plugMemory(Memory& memory) {
    this->memory = &memory;
}

void Mainboard::plugExternalMemory(Memory& external_memory) {
    this->external_memory = &external_memory;
}

bool Mainboard::isRunnable() const {
    if(cpu == nullptr) {
        return false;
    }
    if(ram == nullptr) {
        return false;
    }
    if(memory == nullptr) {
        return false;
    }

    return true;
}


void Mainboard::playProgram(string program_title) {
    if(!isRunnable()) {
        return;
    }

    if(!isOnRAM(program_title)) {
        loadProgram(program_title);
    }
	
	Program* target = ram->get(program_title);
	//Process proc = target->play;
    //cpu->push(target->play);
}


void Mainboard::loadProgram(string program_title) {
    if(!isRunnable()) {
        return;
    }
	Program* target = memory->get(program_title);
    ram->push(target);
}

bool Mainboard::isOnRAM(string program_title) const {
    if(!isRunnable()) {
        return false;
    }
    if(ram->have(program_title)) {
        return true;
    }
    return false;
}
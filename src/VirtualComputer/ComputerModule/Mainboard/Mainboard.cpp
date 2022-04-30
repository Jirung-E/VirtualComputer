#include "Mainboard.hpp"

#include "../../Utils/Utils.hpp"

using namespace std;
using namespace ComputerModule;
using namespace Utils;


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
        loadProgramIntoRAM(program_title);
    }
	
    log("get program from ram.");
	Program* target = ram->get(program_title);
    log("push to cpu...");
    cpu->push(target);
}


void Mainboard::loadProgramIntoRAM(string program_title) {
    if(!isRunnable()) {
        return;
    }
	Program* target = memory->get(program_title);
    ram->push(target);
    log("loaded.");
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
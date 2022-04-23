#include "Mainboard.hpp"

using namespace MainModule;


Mainboard::Mainboard() {

}

Mainboard::~Mainboard() {

}



void Mainboard::putCPU(CPU& cpu) {
    this->cpu = &cpu;
}

void Mainboard::putRAM(RAM& ram) {
    this->ram = &ram;
}

void Mainboard::putMemory(Memory& memory) {
    this->memory = memory;
}

void Mainboard::putExternalMemory(Memory& external_memory) {
    this->external_memory = external_memory;
}
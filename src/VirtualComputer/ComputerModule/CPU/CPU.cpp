#include "CPU.hpp"

using namespace ComputerModule;


CPU::CPU() : program { nullptr }, running_core_num { 0 } {

}

CPU::~CPU() {

}

void CPU::push(Program* program) {
    if(running_core_num >= core_num) {
        return;
    }

    int index = findEmptyCoreIndex();
	
	this->program[index] = program;

    core[index].startProcessing(this->program[index]->play);
}

int CPU::findEmptyCoreIndex() {
    for(int i=0; i<core_num; ++i) {
        if(!core[i].isOccupied()) {
            return i;
        }
    }

    return -1;
}
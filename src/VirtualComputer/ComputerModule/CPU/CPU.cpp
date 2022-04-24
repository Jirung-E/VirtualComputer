#include "CPU.hpp"

using namespace ComputerModule;


CPU::CPU() : running_core_num { 0 } {

}

CPU::~CPU() {

}

void CPU::push(void (*process)()) {
    if(running_core_num >= core_num) {
        return;
    }

    int index = findEmptyCoreIndex();

    core[index].startProcessing(process);
}

int CPU::findEmptyCoreIndex() {
    for(int i=0; i<core_num; ++i) {
        if(!core[i].isOccupied()) {
            return i;
        }
    }

    return -1;
}
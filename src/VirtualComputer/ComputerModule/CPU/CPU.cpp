#include "CPU.hpp"

using namespace ComputerModule;


CPU::CPU() : running_core_num { 0 } {

}

CPU::~CPU() {

}

void CPU::push(Program* program) {
    int index = findEmptyCoreIndex();
	
	if(index < 0) {
		return;
	}
	
    core[index].startProcessing(program);
}

int CPU::findEmptyCoreIndex() {
    for(int i=0; i<core_num; ++i) {
        if(!core[i].isOccupied()) {
            return i;
        }
    }

    return -1;
}
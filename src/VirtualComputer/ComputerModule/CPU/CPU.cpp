#include "CPU.hpp"

#include "../../Utils/Utils.hpp"

using namespace ComputerModule;
using namespace Utils;


CPU::CPU() : running_core_num { 0 } {

}

CPU::~CPU() {

}

void CPU::push(Program* program) {
    log("finding empty core...");
    int index = findEmptyCoreIndex();
	if(index < 0) {
		return;
	}
	
    log("start processing...");
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
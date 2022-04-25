#include "Core.hpp"

using namespace std;
using namespace ComputerModule;


Core::Core() : is_occupied { false } {

}

Core::~Core() {
    
}


void Core::startProcessing(Process process) {
    wait();
	core_thread = thread(&ProcessingUnit::startProcess, &unit, process);
    core_thread.detach();
}

void Core::wait() {
    while(is_occupied) {
        continue;
    }
}

bool Core::isOccupied() {
    return is_occupied;
}
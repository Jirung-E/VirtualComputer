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

void Core::processing(Process process) {
	load(process);
	execute();
	halt();
}

void Core::load(Process process) {
    is_occupied = true;
    this->process = process;
}

void Core::execute() {
    this->process();
}

void Core::halt() {
    is_occupied = false;
}

bool Core::isOccupied() {
    return is_occupied;
}
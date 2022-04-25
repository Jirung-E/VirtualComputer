#include "Core.hpp"

#include "../../Utils/Utils.hpp"

using namespace std;
using namespace ComputerModule;


Core::Core() : is_occupied { false } {

}

Core::~Core() {
    
}


void Core::startProcessing(Process process) {
    wait();
	core_thread = thread(&Core::processing, this, process);
    core_thread.detach();
}

void Core::processing(Process process) {
	//Utils::println("...wtf");
	load(process);
	execute();
	halt();
}

void Core::load(Process process) {
	this->process = process;
	is_occupied = true;
}

void Core::execute() {
	process();
}

void Core::halt() {
	is_occupied = false;
}

void Core::wait() {
    while(is_occupied) {
        continue;
    }
}

bool Core::isOccupied() {
    return is_occupied;
}
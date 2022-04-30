#include "Core.hpp"

#include "../../Utils/Utils.hpp"

using namespace std;
using namespace ComputerModule;


Core::Core() : is_occupied { false } {

}

Core::~Core() {
    
}


void Core::startProcessing(Program* program) {
    wait();
	core_thread = thread([&]() { processing(program); });
    core_thread.detach();
}

void Core::processing(Program* program) {
	load(program);
	execute();
	halt();
}

void Core::load(Program* program) {
	this->program = program;
	is_occupied = true;
}

void Core::execute() {
    program->play();
    program->exit();
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
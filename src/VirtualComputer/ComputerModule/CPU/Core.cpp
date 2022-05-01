#include "Core.hpp"

#include "../../Utils/Utils.hpp"

using namespace std;
using namespace ComputerModule;
using namespace Utils;


Core::Core() : is_occupied { false } {

}

Core::~Core() {
    log("~Core...");
    wait();
}


void Core::startProcessing(Program* program) {
    wait();
    log("new thread..");
    load(program);
    log("loaded.");
	core_thread = thread([&]() { processing(program); });
    log("detach");
    core_thread.detach();
}

void Core::processing(Program* program) {
	execute();
    log("play time is over..");
	halt();
}

void Core::load(Program* program) {
	this->program = program;
	is_occupied = true;
}

void Core::execute() {
    log("call program->play");
    program->play();
}

void Core::halt() {
    log("call program->exit()");
    program->exit();
	is_occupied = false;
}

void Core::wait() {
    log("waiting..");
    while(isOccupied()) {
        continue;
    }
}

bool Core::isOccupied() {
    return is_occupied;
}
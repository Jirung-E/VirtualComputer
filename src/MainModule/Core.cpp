#include "Core.hpp"

using namespace std;
using namespace MainModule;


Core::Core() : process { nullptr } {

}

Core::~Core() {
    if(core_thread.joinable()) {
        halt();
    }
}


void Core::startProcessing(void (*process)()) {
	if(core_thread.joinable()) {
        core_thread.join();
    }
	
	core_thread = thread([&]() { processing(process); });
	core_thread.detach();
}


void Core::processing(void (*process)()) {
    load(process);
    execute();
    halt();
}


void Core::load(void (*process)()) {
    this->process = process;
}

void Core::execute() {
    process();
}

void Core::halt() {
    process = nullptr;
}
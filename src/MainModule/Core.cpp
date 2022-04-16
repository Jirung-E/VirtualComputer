#include "Core.hpp"

using namespace std;
using namespace MainModule;


Core::Core() : is_occupied { false } {

}

Core::~Core() {
    
}


void Core::startProcessing(void (*process)()) {
    wait();
    processing(process);
}


void Core::wait() {
    while(is_occupied) {
        continue;
    }
}

void Core::processing(void (*process)()) {
    load(process);
    core_thread = thread([&]() { execute(); halt(); });
    core_thread.detach();
}

void Core::load(void (*process)()) {
    is_occupied = true;
    this->process = process;
}

void Core::execute() {
    this->process();
}

void Core::halt() {
    is_occupied = false;
}
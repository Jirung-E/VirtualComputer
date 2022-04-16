#include "Core.hpp"

using namespace std;
using namespace MainModule;


Core::Core() : is_occupied { false } {

}

Core::~Core() {
    
}


void Core::startProcessing(void (*process)()) {
    while(is_occupied) {
        continue;
    }
    
    is_occupied = true;
    this->process = process;
    core_thread = thread([&]() { processing(process); });
    core_thread.detach();
}


void Core::processing(void (*process)()) {
    this->process();
    is_occupied = false;
}
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


void Core::processing(void (*process)()) {
    load(process);
    execute();
    halt();
}


void Core::load(void (*process)()) {
    this->process = process;
}

void Core::execute() {
    core_thread = thread([&]() { process(); });
}

void Core::halt() {
    core_thread.join();
    process = nullptr;
}
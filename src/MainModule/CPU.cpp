#include "CPU.hpp"

using namespace MainModule;


void CPU::push(void (*process)()) {
    core[0].startProcessing(process);
}
#include "RAM.hpp"

using namespace ComputerModule;


RAM::RAM(Utils::num_t capacity) : Memory { capacity } {
    
}

RAM::RAM() : RAM { 4 } {
    
}
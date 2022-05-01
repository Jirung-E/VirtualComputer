#include "RAM.hpp"

#include "../../Utils/Utils.hpp"

using namespace ComputerModule;
using namespace Utils;


RAM::RAM(Utils::num_t capacity) : Memory { capacity }, index_to_push { 0 } {
    
}

RAM::RAM() : RAM { 4 } {
    
}


void RAM::push(Program* program) {
    sector[index_to_push].pop();
    sector[index_to_push].push(program);
    increaseIndexToPush();
}

index_t RAM::increaseIndexToPush() {
    index_to_push++;
    if(memorySize() <= index_to_push) {
        index_to_push = 0;
    }
    return index_to_push;
}
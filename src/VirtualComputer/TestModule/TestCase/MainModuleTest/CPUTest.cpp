#include "CPUTest.hpp"

#include "../../../MainModule/CPU.hpp"
#include "../../../Utils/Util.hpp"

using namespace Utils;
using namespace TestModule;
using namespace MainModule;


int CPUTest::main() {
    CPU cpu;
    cpu.push([]() { for(int i=0; i<10; ++i) { println("0: " + toString(i)); } });
    cpu.push([]() { for(int i=0; i<10; ++i) { println("1: " + toString(i)); } });
    cpu.push([]() { for(int i=0; i<10; ++i) { println("2: " + toString(i)); } });
    cpu.push([]() { for(int i=0; i<10; ++i) { println("3: " + toString(i)); } });
    cpu.push([]() { for(int i=0; i<10; ++i) { println("4: " + toString(i)); } });
    cpu.push([]() { for(int i=0; i<10; ++i) { println("5: " + toString(i)); } });
    
    sleep(1000);

    return 0;
}
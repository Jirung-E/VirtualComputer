#include "CPUTest.hpp"

#include "../../../MainModule/CPU.hpp"
#include "../../../Utils/Util.hpp"

using namespace Utils;
using namespace TestModule;
using namespace MainModule;


int CPUTest::main() {
    CPU cpu;
    cpu.push([]() { for(int i=0; i<10; ++i) { println("0: " + toString(i)); } });
    
    sleep(1000);

    return 0;
}
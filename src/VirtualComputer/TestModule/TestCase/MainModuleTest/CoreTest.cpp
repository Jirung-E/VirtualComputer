#include "CoreTest.hpp"

#include "../../../MainModule/Core.hpp"
#include "../../../Utils/Util.hpp"

using namespace Utils;
using namespace TestModule;
using namespace MainModule;


void func() {
    for(int i=0; i<10; ++i) { 
        println("1: " + toString(i)); 
    }
}

void testf() {
    int a = 1;
    int b = 2;
    int c = a + b;
}

int CoreTest::main() {
    Core core;
	Core core2;

    core.startProcessing(func);
	core2.startProcessing([]() { for(int i=0; i<100; ++i) { println("2: " + toString(i)); } });
	
	core.startProcessing([]() { for(int i=0; i<10; ++i) { println("3: " + toString(i)); } });
	core.startProcessing([]() { for(int i=0; i<10; ++i) { println("4: " + toString(i)); } });
	core.startProcessing([]() { for(int i=0; i<10; ++i) { println("5: " + toString(i)); } });
	
	sleep(2000);

    return 0;
}
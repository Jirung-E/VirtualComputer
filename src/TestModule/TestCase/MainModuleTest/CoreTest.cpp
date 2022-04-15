#include "CoreTest.hpp"

#include "../../../MainModule/Core.hpp"
#include "../../../Utils/Util.hpp"

using namespace Utils;
using namespace TestModule;
using namespace MainModule;


int CoreTest::main() {
    Core core;
	Core core2;

    core.startProcessing([]() { for(int i=0; i<10; ++i) { println(toString(i)); } });
	core2.startProcessing([]() { for(int i=0; i<10; ++i) { println("[] : " + toString(i)); } });
	
	core.startProcessing([]() { for(int i=0; i<10; ++i) { println(toString(i)); } });
	core.startProcessing([]() { for(int i=0; i<10; ++i) { println(toString(i)); } });
	core.startProcessing([]() { for(int i=0; i<10; ++i) { println(toString(i)); } });
	
	sleep(1000);

    return 1;
}
#include "CoreTest.hpp"

#include "../../../MainModule/Core.hpp"
#include "../../../Utils/Util.hpp"

using namespace Utils;
using namespace TestModule;
using namespace MainModule;


int CoreTest::main() {
    Core core;

    core.processing([]() { for(int i=0; i<10; ++i) { println(toString(i)); } });

    return 0;
}
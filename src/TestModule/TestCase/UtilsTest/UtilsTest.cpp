#include "UtilsTest.hpp"

#include "../../../Utils/Util.hpp"

using namespace TestModule;
using namespace Utils;


int UtilsTest::main() {
	log("may show_log == false");
	
    show_log = true;

    print("Hello");
    println("Hi");
    log("?");
    errorlog("!");

    show_log = false;
	
	log("may show_log == false");

    return 0;
}
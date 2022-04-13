#include "Test.hpp"

using namespace TestModule;


Test::Test() : test_case { }

void Test::runAllTestCase() {
    for(int i=0; i<test_case_num; ++i) {
        test_case->main();
    }
}
#include "Test.hpp"

#include "../Utils/Util.hpp"
#include "TestCase/TestCases.hpp"

using namespace TestModule;
using namespace Utils;


Test::Test() : test_case { new TestCase*[1] }, test_case_num { 1 } {
	test_case[0] = new UtilsTest();
}

Test::~Test() {
    delete[] test_case;
}

void Test::runAllTestCase() {
    for(int i=0; i<test_case_num; ++i) {
        //test_case[i]->main();
    }
}

void Test::startTestAndShowResult() {
    for(int i=0; i<test_case_num; ++i) {
        print("TestCase[" + std::to_string(i) + "]: ");

        int test_result = test_case[i]->main();
        if(test_result == 0) {
            println("Passed.");
        }
        else {
            println("Failed. (Error Code: " + test_result);
        }
    }
}
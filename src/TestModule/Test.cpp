#include "Test.hpp"

#include "../Utils/Util.hpp"

using namespace TestModule;
using namespace Utils;


Test::Test() : test_case { new TestCase*[10] }, test_case_num { 10 } {

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
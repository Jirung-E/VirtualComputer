#ifndef Test_hpp
#define Test_hpp

#include "TestCase/TestCase.hpp"


namespace TestModule {
    class Test {
        private: int test_case_num;
        private: TestCase** test_case;

    public:
        Test();
        ~Test();

        public: void runAllTestCase();
        public: void startTestAndShowResult();
    };
}

#endif
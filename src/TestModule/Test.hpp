#ifndef Test_hpp
#define Test_hpp

#include "TestCase/TestCase.hpp"


namespace TestModule {
    class Test {
        private: const int test_case_num = 200;
        private: TestCase* test_case[200];

    public:
        Test();
        ~Test();

        public: void startTestAndShowResult();
    };
}

#endif
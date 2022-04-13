#ifndef Test_hpp
#define Test_hpp

#include "TestCase/TestCase.hpp"


namespace TestModule {
    class Test {
        private: TestCase** test_case;

    public:
        void executeAllTestCase();
    };
}

#endif
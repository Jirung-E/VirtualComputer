#ifndef Test_hpp
#define Test_hpp

namespace TestModule {
    class Test {
        private: TestCase** test_case;

    public:
        void executeAllTestCase();
    };
}

#endif
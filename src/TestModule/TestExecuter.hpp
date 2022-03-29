#ifndef TestExecuter_hpp
#define TestExecuter_hpp

#include "Test1/Test1.hpp"


namespace Jirung_E {
    namespace VirtualComputer {
        namespace TestModule {
            class TestExecuter {
                protected: ITest* test_target;

            public:
                TestExecuter(const ITest& test_target);
                
                void Test();
            };
        }
    }
}

#endif
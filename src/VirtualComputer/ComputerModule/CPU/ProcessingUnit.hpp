#ifndef ProcessingUnit_hpp
#define ProcessingUnit_hpp

namespace ComputerModule {
    using Process = void (*)();

    class ProcessingUnit {
        private: Process process;           // -> Resister
    public:
        ProcessingUnit();
        ~ProcessingUnit();

        void startProcess(Process process);
    };
}

#endif
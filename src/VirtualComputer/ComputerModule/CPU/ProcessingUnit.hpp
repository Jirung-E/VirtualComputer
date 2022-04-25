#ifndef ProcessingUnit_hpp
#define ProcessingUnit_hpp

namespace ComputerModule {
    using Process = void (*)();

    class ProcessingUnit {
    public:
        ProcessingUnit();
        ~ProcessingUnit();

        void startProcess(Process process);
    };
}

#endif
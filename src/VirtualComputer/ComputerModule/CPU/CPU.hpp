#ifndef CPU_hpp
#define CPU_hpp

#include "Core.hpp"
#include "../../Utils/UtilTypes.hpp"


namespace ComputerModule {
    class CPU {
        private: Core core[4];
        private: const Utils::num_t core_num = 4;
        private: Utils::num_t running_core_num;

    public:
        CPU();
        ~CPU();

        public: void push(Process process);

        private: int findEmptyCoreIndex();
    };
}

#endif
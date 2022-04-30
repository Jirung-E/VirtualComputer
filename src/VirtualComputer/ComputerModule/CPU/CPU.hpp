#ifndef CPU_hpp
#define CPU_hpp

#include "Core.hpp"
#include "../Program/Program.hpp"
#include "../../Utils/UtilTypes.hpp"


namespace ComputerModule {
    class CPU {
        private: const Utils::num_t core_num;
        private: Core* const core;
        private: Utils::num_t running_core_num;

    public:
        CPU(Utils::num_t num_of_cores);
        CPU();
        ~CPU();
		
        void push(Program* program);

        private: int findEmptyCoreIndex();
    };
}

#endif
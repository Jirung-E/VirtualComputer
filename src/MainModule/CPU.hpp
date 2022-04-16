#ifndef CPU_hpp
#define CPU_hpp

#include "Core.hpp"
#include "../Utils/Util.hpp"


namespace MainModule {
    class CPU {
        private: Core core[4];
        private: const Utils::num_t core_num = 4;

    public:
        // CPU();
        // ~CPU();

        public: void push(void (*process)());
    };
}

#endif
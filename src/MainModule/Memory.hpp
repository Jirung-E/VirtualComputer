#ifndef Memory_hpp
#define Memory_hpp

#include "../Utils/Util.hpp"
#include "Sector.hpp"


namespace MainModule {
    class Memory {
        private: Utils::num_t sector_num;
        private: Sector* sector;

    public:
        Memory(Utils::num_t sector_num);
        ~Memory();

        void push(Program* program);
    };
}

#endif
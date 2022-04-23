#ifndef Memory_hpp
#define Memory_hpp

#include "../Utils/Util.hpp"
#include "Sector.hpp"


namespace MainModule {
    class Memory {
        private: Utils::num_t num_of_sectors;
        private: Sector* sector;

    private:
        Utils::num_t numOfFilledSectors() const;

    public:
        Memory(Utils::num_t num_of_sectors);
        ~Memory();

        void push(Program* program);
        float getPercentOfMemoryIsFilled() const;
    };
}

#endif
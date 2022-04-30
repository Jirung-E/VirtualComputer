#ifndef Memory_hpp
#define Memory_hpp

#include "../../Utils/UtilTypes.hpp"
#include "Sector.hpp"


namespace ComputerModule {
    class Memory {
        private: const Utils::num_t num_of_sectors;
        private: Sector* const sector;

    private:
        Utils::num_t numOfFilledSectors() const;
        int indexOf(std::string title) const;

    public:
        Memory(Utils::num_t num_of_sectors);
        ~Memory();

        size_t memorySize() const;
        float percentageOfMemoryFilled() const;

        void push(Program* program);
        void pop(std::string title);
        Program* get(std::string title);
		bool have(std::string title) const;
    };
}

#endif
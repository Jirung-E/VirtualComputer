#ifndef RAM_hpp
#define RAM_hpp

#include "Memory.hpp"
#include "../../Utils/UtilTypes.hpp"


namespace ComputerModule {
    class RAM : public Memory {
    public:
        RAM(Utils::num_t capacity);
        RAM();
    };
}

#endif
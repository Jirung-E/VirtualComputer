#ifndef RAM_hpp
#define RAM_hpp

#include "Memory.hpp"
#include "../../Utils/UtilTypes.hpp"


namespace ComputerModule {
    class RAM : public Memory {
        private: Utils::index_t index_to_push;
        
    public:
        RAM(Utils::num_t capacity);
        RAM();
        
        void push(Program* program);
        
    private:
        Utils::index_t increaseIndexToPush();
    };
}

#endif
#ifndef Sector_hpp
#define Sector_hpp

#include "Program.hpp"


namespace MainModule {
    class Sector {
        private: Program* program;
        private: bool is_empty;

    public:
        Sector();

        bool isEmpty() const;
        
        void push(Program* program);
        void pop();
    };
}

#endif
#ifndef Sector_hpp
#define Sector_hpp

#include "../Program/Program.hpp"


namespace ComputerModule {
    class Sector {
        private: Program* program;
        private: bool is_empty;

    public:
        Sector();

        bool isEmpty() const;
        
        void push(Program* program);
        void pop();
        Program* const getData();
    };
}

#endif
#ifndef Core_hpp
#define Core_hpp

#include <thread>

#include "ProcessingUnit.hpp"


namespace ComputerModule {
    class Core {
        private: std::thread core_thread;
        private: ProcessingUnit unit;
        private: bool is_occupied;

    public:
        Core();
        ~Core();

        public: void startProcessing(Process process);

        private: void wait();

        public: bool isOccupied();
    };
}

#endif
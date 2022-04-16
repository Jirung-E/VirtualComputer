#ifndef Core_hpp
#define Core_hpp

#include <thread>


namespace MainModule {
    class Core {
        private: std::thread core_thread;
        private: void (*process)();
        private: bool is_occupied;

    public:
        Core();
        ~Core();

        public: void startProcessing(void (*process)());

        private: void processing(void (*process)());

        private: void wait();
        private: void load(void (*process)());
        private: void execute();
        private: void halt();

        public: bool isOccupied();
    };
}

#endif
#ifndef Core_hpp
#define Core_hpp

#include <thread>


namespace MainModule {
    class Core {
        private: std::thread core_thread;

        private: void load();
        private: void execute();
        private: void halt();

    public:
        Core();
        ~Core();

        void processing(void (*process)());
    };
}

#endif
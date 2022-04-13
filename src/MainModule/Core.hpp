#ifndef Core_hpp
#define Core_hpp

#include <thread>


namespace MainModule {
    class Core {
        private: std::thread core_thread;
        private: void (*process)();

    public:
        Core();
        ~Core();

        public: void processing(void (*process)());

        private: void load(void (*process)());
        private: void execute();
        private: void halt();
    };
}

#endif
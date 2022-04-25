#ifndef Core_hpp
#define Core_hpp

#include <thread>


namespace ComputerModule {
	using Process = void (*)();
	
	class ProcessingUnit {
		private: std::thread thread_;
	};
	
    class Core {
        private: std::thread core_thread;
        private: Process process;
        private: bool is_occupied;

    public:
        Core();
        ~Core();

        public: void startProcessing(Process process);

        private: void processing(Process process);

        private: void wait();
        private: void load(Process process);
        private: void execute();
        private: void halt();

        public: bool isOccupied();
    };
}

#endif
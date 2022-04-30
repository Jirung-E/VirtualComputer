#ifndef Core_hpp
#define Core_hpp

#include <thread>

#include "../Program/Program.hpp"


namespace ComputerModule {
	using Process = void (*)();            // 각 보다가 삭제예정
	
    class Core {
        private: std::thread core_thread;
        private: Program* program;        // -> Resister
        private: bool is_occupied;

    public:
        Core();
        ~Core();

        public: void startProcessing(Program* program);
        
		private: void processing(Program* program);
		private: void load(Program* program);
		private: void execute();
		private: void halt();

        private: void wait();

        public: bool isOccupied();
    };
}

#endif
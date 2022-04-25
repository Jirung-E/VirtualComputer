#ifndef Program_hpp
#define Program_hpp

#include <string>


namespace ComputerModule {
    class Program {
        private: const std::string title_;

    public:
        Program(std::string title);
        virtual ~Program();

        std::string title() const;

        virtual void play();
        virtual void exit();
    };
}

#endif
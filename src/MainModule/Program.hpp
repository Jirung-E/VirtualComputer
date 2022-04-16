#ifndef Program_hpp
#define Program_hpp

#include <string>


namespace MainModule {
    class Program {
        private: const std::string title;

    public:
        Program(std::string title);
        virtual ~Program();

        std::string Title() const;

        virtual void play() = 0;
        virtual void exit() = 0;
    };
}

#endif
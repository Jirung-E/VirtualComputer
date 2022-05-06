#ifndef Canvas_hpp
#define Canvas_hpp

#include <string>

#include "../TxtImage/TxtImage.hpp"


namespace GameModule {
    class Canvas {
        private: unsigned int width;
        private: unsigned int height;
        private: char** pixel;

    public:
        Canvas(unsigned int width, unsigned int height);
        Canvas();
        ~Canvas();

    public:
        void draw(const TxtImage& txtimg, int x, int y, bool transparent_background = true);
        void draw(const std::string& text, int x, int y, bool transparent_background = true);
        
        void show() const;        // 주의! 이거 나중에 클래스 분리해야함. 출력을 담당하는 클래스를 따로 만들거임.
        
        void clearTo(char default_background);
        void resize(unsigned int width, unsigned int height);
    };
}

#endif
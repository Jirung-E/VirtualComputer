#ifndef TxtImage_hpp
#define TxtImage_hpp

#include <string>


namespace GameModule {
    class TxtImage {
        private: unsigned int width;
        private: unsigned int height;
        private: char** pixel;

    public:
        TxtImage(std::string file_name);
        TxtImage();
        ~TxtImage();
        
        unsigned short getWidth() const;
        unsigned short getHeight() const;
        char** getByCharpp() const;
        std::string getByString() const;
    };
}

#endif
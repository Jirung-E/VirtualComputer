#include "Canvas.hpp"

#include "../../../VirtualComputer/Utils/Utils.hpp"

using namespace std;
using namespace GameModule;
using namespace Utils;


Canvas::Canvas(unsigned int width, unsigned int height) : width { width }, height { height }, pixel { new char*[height] } {
    for(int i=0; i<height; ++i) {
        pixel[i] = new char[width];
    }
    
    clearTo('.');
}

Canvas::Canvas() : Canvas(64, 32) {
    
}

Canvas::~Canvas() {
    for(int i=0; i<height; ++i) {
        delete[] pixel[i];
    }
    delete[] pixel;
}


void Canvas::draw(const TxtImage& txtimg, int x, int y, bool transparent_background) {
    char** img = txtimg.getByCharpp();
    for(int i=0; i<txtimg.getHeight(); ++i) {
        for(int k=0; k<txtimg.getWidth(); ++k) {
            if(i+y < 0 || k+x < 0) {
                continue;
            }
            if(i+y >= height || k+x >= width) {
                continue;
            }
            if(transparent_background == true) {
                if(img[i][k] == ' ') {
                    continue;
                }
            }
            pixel[i+y][k+x] = img[i][k];
        }
    }
}

void Canvas::draw(const string& text, int x, int y, bool transparent_background) {
    for(int i=0; i<text.length(); ++i) {
        char c = text.at(i);
        if(c == '\n') {
            y++;
            x -= i;
            continue;
        }
        
        if(y < 0 || x < 0) {
            continue;
        }
        if(y >= height || x >= width) {
            continue;
        }
        if(transparent_background == true) {
            if(c == ' ') {
                x++;
                continue;
            }
        }

        pixel[y][x] = c;
        x++;
    }
}

void Canvas::show() const {
    for(int i=0; i<height; ++i) {
        for(int k=0; k<width; ++k) {
            printf("%c", pixel[i][k]);
        }
        println("");
    }
}

void Canvas::clearTo(char default_background) {
    for(int i=0; i<height; ++i) {
        for(int k=0; k<width; ++k) {
            pixel[i][k] = default_background;
        }
    }
}

void Canvas::resize(unsigned int width, unsigned int height) {
    for(int i=0; i<this->height; ++i) {
        delete[] pixel[i];
    }
    delete[] pixel;
    
    this->width = width;
    this->height = height;

    pixel = new char*[height];
    for(int i=0; i<height; ++i) {
        pixel[i] = new char[width];
    }
    clearTo('.');
}
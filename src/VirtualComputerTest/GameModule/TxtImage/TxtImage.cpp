#include "TxtImage.hpp"

#include <fstream>
#include <iostream>

#include "../../../VirtualComputer/Utils/Utils.hpp"

using namespace std;
using namespace GameModule;
using namespace Utils;


TxtImage::TxtImage() : width { 1 }, height { 1 }, pixel { } {
    pixel = new char*[height];
    for(int i=0; i<height; ++i) {
        pixel[i] = new char[width];
    }
}

TxtImage::TxtImage(string file_name) : width { 0 }, height { 0 }, pixel { } {
    ifstream file { file_name };
    if(file.is_open()) {
        file >> width >> height;
        string buffer_erase;
        getline(file, buffer_erase);

        pixel = new char*[height];
        for(int i=0; i<height; ++i) {
            pixel[i] = new char[width];
        }

        for(int i=0; i<height; ++i) {
            string line;
            getline(file, line);
            for(int k=0; k<width; ++k) {
                pixel[i][k] = line.at(k);
            }
        }
    }
    file.close();
}

TxtImage::~TxtImage() {
    for(int i=0; i<height; ++i) {
        delete[] pixel[i];
    }
    delete[] pixel;
}

unsigned short TxtImage::getWidth() const {
	return width;
}

unsigned short TxtImage::getHeight() const {
	return height;
}

char** TxtImage::getByCharpp() const {
    return pixel;
}

string TxtImage::getByString() const {
    string result = "";
    for(int i=0; i<height; ++i) {
        for(int k=0; k<width; ++k) {
            result += pixel[i][k];
        }
        result += '\n';
    }
    result.pop_back();
    return result;
}
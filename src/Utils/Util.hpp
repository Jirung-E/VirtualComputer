#ifndef Util_hpp
#define Util_hpp

#include <string>


namespace Utils {
    typedef unsigned short index_t;
    bool show_log = false;

    void print(std::string str);
    void log(std::string str);
}

#endif
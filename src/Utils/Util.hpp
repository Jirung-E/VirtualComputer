#ifndef Util_hpp
#define Util_hpp

#include <string>


namespace Utils {
    typedef unsigned short index_t;
    typedef unsigned short count_t;
    typedef unsigned short num_t;

    bool show_log = false;

    void print(std::string str);
    void println(std::string str);
    void log(std::string str);
    void errorlog(std::string str);
}

#endif
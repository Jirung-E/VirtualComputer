#ifndef Utils_hpp
#define Utils_hpp

#include <string>

#include "UtilTypes.hpp"


namespace Utils {
    extern bool show_log;

    void print(std::string str);
    void println(std::string str);
    void log(std::string str);
    void errorlog(std::string str);

    std::string toString(int num);
    std::string toString(float num);
    std::string toString(bool b);

    bool failed();
    bool success();
	
	void sleep(unsigned short time);
}

#endif
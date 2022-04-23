#ifndef Util_hpp
#define Util_hpp

#include <string>
#include <chrono>
#include <thread>


namespace Utils {
    typedef unsigned short index_t;
    typedef unsigned short count_t;
    typedef unsigned short num_t;

    extern bool show_log;

    void print(std::string str);
    void println(std::string str);
    void log(std::string str);
    void errorlog(std::string str);

    std::string toString(int num);
    std::string toString(float num);

    bool failed();
    bool success();
	
	void sleep(unsigned short time);
}

#endif
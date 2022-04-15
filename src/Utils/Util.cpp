#include "Util.hpp"

#include <iostream>

//using namespace std;


namespace Utils {
    void print(std::string str) {
        printf("%s", str.c_str());
    }

    void println(std::string str) {
        printf("%s\n", str.c_str());
    }

    void log(std::string str) {
        if(show_log == true) {
            printf("log: %s\n", str.c_str());
        }
    }

    void errorlog(std::string str) {
        if(show_log == true) {
            printf("error log: %s\n", str.c_str());
        }
    }
}
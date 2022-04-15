#include "Util.hpp"

#include <iostream>

using namespace std;


namespace Utils {
	bool show_log = false;
	
    void print(string str) {
        printf("%s", str.c_str());
    }

    void println(string str) {
        printf("%s\n", str.c_str());
    }

    void log(string str) {
        if(show_log == true) {
            printf("log: %s\n", str.c_str());
        }
    }

    void errorlog(string str) {
        if(show_log == true) {
            printf("error log: %s\n", str.c_str());
        }
    }
}
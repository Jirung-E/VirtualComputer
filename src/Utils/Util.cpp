#include "Util.hpp"
#include <iostream>

using namespace std;


namespace Utils {
    void print(string str) {
        printf("%s\n", str.c_str());
    }

    void log(string str) {
        if(show_log == true) {
            printf("log: %s\n", str.c_str());
        }
    }
}
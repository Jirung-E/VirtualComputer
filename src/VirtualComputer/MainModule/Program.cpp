#include "Program.hpp"

using namespace std;
using namespace MainModule;


Program::Program(string title) : title_ { title } {

}

virtual Program::~Program() {

}

std::string Program::title() const {
    return title;
}
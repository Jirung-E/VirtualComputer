#include "Program.hpp"

using namespace std;
using namespace MainModule;


Program::Program(string title) : title_ { title } {

}

Program::~Program() {

}

std::string Program::title() const {
    return title_;
}
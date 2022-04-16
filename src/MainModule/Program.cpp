#include "Program.hpp"

using namespace std;
using namespace MainModule;


Program::Program(string title) : title { title } {

}

Program::~Program() {

}

std::string Program::Title() const {
    return title;
}
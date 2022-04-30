#include "Program.hpp"

#include "../../Utils/Utils.hpp"

using namespace std;
using namespace ComputerModule;


Program::Program(string title) : title_ { title } {

}

Program::~Program() {

}

std::string Program::title() const {
    return title_;
}
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

void Program::play() {
	// 아무것도 하지 말것
}

void Program::exit() {
	// 아무것도 하지 말것
}
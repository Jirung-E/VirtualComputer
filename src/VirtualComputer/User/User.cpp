#include "User.hpp"

#include "../Utils/Utils.hpp"

using namespace std;
using namespace UserModule;
using namespace Utils;


User::User(std::string name) : name { name }, pc { nullptr } {

}

User::~User() {
    
}


void User::say(string dialogue) const {
    println("[" + name + "]: " + dialogue);
}

void User::setComputer(ComputerModule::Computer* computer) {
    pc = computer;
}

void User::turnOnTheComputer() {
    if(!haveComputer())  {
        say("I don't have a computer...");
        return;
    }
    pc->powerOn();
}

void User::turnOffTheComputer() {
    if(!haveComputer())  {
        say("I don't have a computer...");
        return;
    }
    pc->powerOff();
}

bool User::haveComputer() const {
    if(pc == nullptr) {
        return false;
    }
    return true;
}

ComputerModule::Computer* User::computer() {
    return pc;
}
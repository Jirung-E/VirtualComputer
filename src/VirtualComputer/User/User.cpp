#include "User.hpp"

using namespace std;
using namespace UserModule;


User::User(std::string name) : name { name }, main_memory { 32 }, external_memory { 16 } {

}

User::~User() {
    
}
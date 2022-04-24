#include "Sector.hpp"

using namespace MainModule;


Sector::Sector() : program { nullptr }, is_empty { true } {

}

bool Sector::isEmpty() const {
    return is_empty;
}

void Sector::push(Program* program) {
    if(isEmpty()) {
        this->program = program;
        is_empty = false;
    }
}

void Sector::pop() {
    this->program = nullptr;
    is_empty = true;
}

Program* const Sector::getData() {
    return program;
}
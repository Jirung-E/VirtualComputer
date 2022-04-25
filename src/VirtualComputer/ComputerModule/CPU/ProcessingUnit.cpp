#include "ProcessingUnit.hpp"

using namespace ComputerModule;
using namespace std;


ProcessingUnit::ProcessingUnit() {

}

ProcessingUnit::~ProcessingUnit() {

}


void ProcessingUnit::startProcess(Process process) {
    process();
}
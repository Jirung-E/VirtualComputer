#include "Memory.hpp"

using namespace std;
using namespace MainModule;
using namespace Utils;


Memory::Memory(num_t num_of_sectors) : num_of_sectors { num_of_sectors }, sector { new Sector[num_of_sectors] } {

}

Memory::~Memory() {
    delete[] sector;
}


num_t Memory::numOfFilledSectors() const {
    num_t num_of_filled_sectors = 0;
    for(int i=0; i<num_of_sectors; ++i) {
        if(sector[i].isEmpty() == false) {
            num_of_filled_sectors++;
        }
    }
    
    return num_of_filled_sectors;
}

void Memory::push(Program* program) {
    for(int i=0; i<num_of_sectors; ++i) {
        if(sector[i].isEmpty()) {
            sector[i].push(program);
            break;
        }
    }
}

float Memory::getPercentOfMemoryIsFilled() const {
    return (static_cast<float>(numOfFilledSectors()) / static_cast<float>(num_of_sectors)) * 100.0;
}
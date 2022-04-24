#include "Memory.hpp"

using namespace std;
using namespace ComputerModule;
using namespace Utils;


Memory::Memory(num_t num_of_sectors) : num_of_sectors { num_of_sectors }, sector { nullptr } {
    if(this->num_of_sectors <= 0) {
        this->num_of_sectors = 1;
    }
    sector = new Sector[num_of_sectors];
}

Memory::~Memory() {
    delete[] sector;
}


num_t Memory::numOfFilledSectors() const {
    num_t num_of_filled_sectors = 0;
    for(int i=0; i<memorySize(); ++i) {
        if(sector[i].isEmpty() == false) {
            num_of_filled_sectors++;
        }
    }
    
    return num_of_filled_sectors;
}

unsigned int Memory::indexOf(string title) const {
    for(int i=0; i<memorySize(); ++i) {
        if(sector[i].isEmpty() == false) {
            if(sector[i].getData()->title() == title) {
                return i;
            }
        }
    }

    return -1;
}


size_t Memory::memorySize() const {
    return num_of_sectors;
}

float Memory::percentageOfMemoryFilled() const {
    return (static_cast<float>(numOfFilledSectors()) / static_cast<float>(memorySize())) * 100.0;
}

void Memory::push(Program* program) {
    for(int i=0; i<memorySize(); ++i) {
        if(sector[i].isEmpty()) {
            sector[i].push(program);
            break;
        }
    }
    // 여기까지 오면 push 실패임.
}

void Memory::pop(string title) {
    int idx = indexOf(title);
    if(idx >= 0) {
        sector[idx].pop();
    }
}

Program* Memory::get(string title) {
    int idx = indexOf(title);
    if(idx >= 0) {
        return sector[idx].getData();
    }

    return nullptr;
}

bool Memory::have(string title) const {
	if(indexOf(title) >= 0) {
		return true;
	}
	return false;
}
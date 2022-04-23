#include "Memory.hpp"

using namespace std;
using namespace MainModule;
using namespace Utils;


Memory::Memory(num_t sector_num) : sector_num { sector_num }, sector { new Sector[sector_num] } {

}

Memory::~Memory() {
    delete[] sector;
}
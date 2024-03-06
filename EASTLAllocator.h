#ifndef DATASTRUCTURES_EASTLALLOCATOR_H
#define DATASTRUCTURES_EASTLALLOCATOR_H

#include <cstdint>

void* operator new[](size_t size, const char* name, int flags, unsigned debugFlags, const char* file, int line)
{
    return new uint8_t[size];
}

#endif //DATASTRUCTURES_EASTLALLOCATOR_H

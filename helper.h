#ifndef HELPER_H
#define HELPER_H
#include <vector>

template<typename T>
void initVectorFromArray(std::vector<T>& toInit, T array[])
{
    std::vector<T> helper = std::vector<T>(array,array + 10);
    toInit = helper;
}
#endif // HELPER_H


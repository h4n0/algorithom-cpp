#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <iostream>

template <typename T>
int binarySearch(const std::vector<T>& array, unsigned start, unsigned end, const T& key)
{
    if(start > end)
    {
        return -1;
    }

    unsigned middle = start + ((end - start) / 2);

    if(array[middle] == key)
    {
        return middle;
    }
    else if(array[middle] > key)
    {
        return binarySearch(array, start, middle - 1, key);
    }
    else
    {
        return binarySearch(array, middle + 1, end, key);
    }
}



#endif

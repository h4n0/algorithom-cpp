#include "mergeSort.h"
#include <vector>

template <typename T>
std::vector<T> mergeSort(std::vector<T> array)
{
    if(array.size() == 1)
    {
        return array;
    }

    std::vector<T>::iterator middle = array.begin() + (array.size() / 2);


}

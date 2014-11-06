#include "mergeSort.h"
#include <vector>

template <typename T>
std::vector<T> mergeSort(const std::vector<T>& array)
{
    if(array.size() == 1)
    {
        return array;
    }

    std::vector<T>::iterator middle = array.begin() + (array.size() / 2);

    std::vector<T> left(array.begin(), middle);
    std::vector<T> right(middle, array.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(array, left, right);
}

template <typename T>


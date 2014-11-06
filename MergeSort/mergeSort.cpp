/************************************************************
 * heavily refer to the following implementation
 * http://en.wikibooks.org/wiki/Algorithm_Implementation/Sorting/Merge_sort#C.2B.2B
 ***********************************************************/
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

    // so called range constructor for std vector. see more with
    // http://www.cplusplus.com/reference/vector/vector/vector/
    left = mergeSort(left);
    right = mergeSort(right);

    return merge(array, left, right);
}

template <typename T>
std::vector<T> merge(std::vector<T>& array, const std::vector<T>& left, const std::vector<T>& right)
{
}

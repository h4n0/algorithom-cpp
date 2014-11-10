/************************************************************
 * refer to the following implementation
 * http://en.wikibooks.org/wiki/Algorithm_Implementation/Sorting/Merge_sort#C.2B.2B
 ***********************************************************/
#ifndef MERGESORT_H
#define MERGESORT_H

// for non-specialized template must be visible to translation unit
// see http://stackoverflow.com/questions/10632251/undefined-reference-to-template-function
#include <iostream>
#include <vector>

template <typename T>
std::vector<T> mergeSort(std::vector<T>& array);

template <typename T>
void merge(std::vector<T>& array, const std::vector<T>& left, const std::vector<T>& right);

template <typename T>
std::vector<T> mergeSort(std::vector<T>& array)
{
    if(array.size() == 1)
    {
        return array;
    }

    typename std::vector<T>::iterator middle = array.begin() + (array.size() / 2);

    // so called range constructor for std vector. see more with
    // http://www.cplusplus.com/reference/vector/vector/vector/
    std::vector<T> left(array.begin(), middle);
    std::vector<T> right(middle, array.end());

    left = mergeSort(left);
    right = mergeSort(right);

    // assign merge result to result so that to avoid return for merge function
    std::vector<T> result;
    merge(result, left, right);
    return result;
}

template <typename T>
void merge(std::vector<T>& array, const std::vector<T>& left, const std::vector<T>& right)
{
    std::vector<T> result;
    unsigned int left_i = 0, right_i = 0;

    for(unsigned int i = 0; i < (left.size() + right.size()); i++)
    {
       // when both left and right haven't meet the end
       if(left_i < left.size() && right_i < right.size())
       {
           if(left[left_i] <= right[right_i])
           {
               result.push_back(left[left_i]);
               left_i++;
           }
           else
           {
               result.push_back(right[right_i]);
               right_i++;
           }
       } 
       // when left has meet the end
       else if (left_i >= left.size())
       {
           result.push_back(right[right_i]);
           right_i++;
       }
       // when right has meet the end
       else if (right_i >= right.size())
       {
           result.push_back(left[left_i]);
           left_i++;
       }
    }

    // display merge process
//    for(unsigned j=0;j<result.size();j++)
//    {
//        std::cout<<result[j]<<" ";
//    }

    // assign the result back to array 
    array = result;
}

#endif

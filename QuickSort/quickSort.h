/*********************************************************
 * Reference to the source code
 * http://en.wikibooks.org/wiki/Algorithm_Implementation/Sorting/Quicksort#C.2B.2B
 * ******************************************************/
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <functional>   // std::less_equal
#include <algorithm>    // std::iter_swap
#include <iterator>     // std::iterator_traits

template <typename BidirectionalIterator, typename Compare>
void quickSort(BidirectionalIterator first, BidirectionalIterator last, Compare compare)
{
    if( first != last)
    {
        BidirectionalIterator left = first;
        BidirectionalIterator right = last;
        // assign current first to pivot and then first++
        // a little bit zhuangbi(chinese) to implement like this
        BidirectionalIterator pivot = first++;

        while()


    }
}


#endif

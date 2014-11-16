/*********************************************************
 * Reference to the source code
 * http://en.wikibooks.org/wiki/Algorithm_Implementation/Sorting/Quicksort#C.2B.2B
 * ******************************************************/
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <functional>   // std::less_equal
#include <algorithm>    // std::swap
#include <iterator>     // std::iterator_traits

// Here the parameter last is not pointed to last element, but the one afte last one
// that is the commen implementation for C++ STL Iterator. see
// http://stackoverflow.com/questions/13494891/iterate-over-range-with-given-first-and-last-iterator
// http://arsenmk.blogspot.de/2013/03/quick-sort-implementation.html at "std::advance(right, -1);"
template <typename BidirectionalIterator, typename Compare>
void QuickSort(BidirectionalIterator first, BidirectionalIterator last, Compare compare)
{
    if( first != last)
    {
        BidirectionalIterator left = first;
        BidirectionalIterator right = last;
        // assign current first to pivot and then left++
        // a little bit zhuangbi(chinese) to implement like this
        BidirectionalIterator pivot = left++;

        // right is the iterator after last element, so if left is equal to right,
        // the loop should be over
        while( left != right )
        {
            if(compare(*left, *pivot))
            {
                // in any case, "prefer ++i over i++" and you won't go wrong
                // http://stackoverflow.com/questions/24853/what-is-the-difference-between-i-and-i
                ++left;
            }
            else
            {
                // make sure that right is not pointed to past-the-end 
                // https://gcc.gnu.org/onlinedocs/libstdc++/manual/iterators.html
                if(right == last)
                    --right;
                else
                {
                    while((left != right) && compare( *pivot, *right))
                    {
                        --right;
                    }
                    std::swap( *left, *right);
                }
            }

        }

        // left now is closed to right
        // pivot, ..., left, right, ...
        --left;
        std::swap( *pivot, *left);

        QuickSort( first, left, compare);
        QuickSort( right, last, compare);

    }
}

template< typename BidirectionalIterator>
inline void QuickSort(BidirectionalIterator first, BidirectionalIterator last)
{
    QuickSort(first, last,
            std::less_equal<typename std::iterator_traits<BidirectionalIterator>::value_type>()
            );
}

#endif

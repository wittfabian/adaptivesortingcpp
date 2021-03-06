// ======================================================================
//
// Copyright (c) 2015 OVGU Magdeburg
//
// This software and related files are part of an Algorithm Engineering
// implementation project on adaptive sorting of polygon vertices,
// conducted at computer science department (FIN) at OVGU Magdeburg,
// Germany. All rights reserved.
//
// ======================================================================
//
//  adaptivesorting
//
//  Created by Fabian Witt on 17.11.15.
//  Copyright (c) 2015 Fabian Witt. All rights reserved.
//
// ======================================================================

#ifndef FWI_H
#define FWI_H

namespace FWI {
    
    //swap the content of a and b
    template <class T>
    void swap( T& a, T& b ){
        T temp(a); a = b; b = temp;
    }
    
    // insertion sort algorithm
    template <class RandomAccessIterator, class Less>
    void insertionSort(RandomAccessIterator first, RandomAccessIterator beyond, Less less ){
        
        for(auto iter = first; iter != beyond; ++iter){
            
            for(auto iter2 = iter; iter2 != first && less(*iter2, *(iter2-1)); iter2--){
                FWI::swap(*(iter2), *(iter2-1));
            }
        }
    }
    
    // merge sort algorithm
    template <class RandomAccessIterator, class Less>
    void mergeSort(RandomAccessIterator first, RandomAccessIterator beyond, Less less ){
        
        if (beyond - first > 1){
            RandomAccessIterator middle = first + (beyond - first) / 2;
            if(middle - first > 50){
                FWI::mergeSort(first, middle, less);
            } else {
                FWI::insertionSort(first, beyond, less);
            }
                    
            if(beyond - middle > 50){
                FWI::mergeSort(middle, beyond, less);
            } else {
                FWI::insertionSort(middle, beyond, less);
            }
            std::inplace_merge(first, middle, beyond, less);
        }
    }
    
    // sort the content from first until beyond with the provided less function
    template <class RandomAccessIterator, class Less>
    void sort(RandomAccessIterator first, RandomAccessIterator beyond, Less less ){
        
        if( !std::is_sorted(first, beyond) ){
            
            if( beyond - first > 50){
                FWI::mergeSort(first, beyond, less);
            } else {
                FWI::insertionSort(first, beyond, less);
            }
        }
    }
    
    // call the sorting function and return the result as an OutputIterator
    template <class InputIterator, class OutputIterator, class Less>
    OutputIterator sort(InputIterator first, InputIterator beyond, OutputIterator result, Less less ){
        
        typedef typename std::iterator_traits<InputIterator>::value_type ValueType;
        
        std::vector<ValueType> V;
        
        std::copy(first,beyond,std::back_inserter(V));
        
        FWI::sort(V.begin(), V.end(), less);
        
        return std::copy(V.begin(), V.end(), result);
    }
}

#endif // FWI_H
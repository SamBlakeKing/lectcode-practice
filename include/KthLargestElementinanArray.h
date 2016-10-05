//
// Created by dell on 9/22/16.
//

#ifndef LECTCODE_PRACTICE_KTHLARGESTELEMENTINANARRAY_H
#define LECTCODE_PRACTICE_KTHLARGESTELEMENTINANARRAY_H

#include <vector>
#include <iostream>

class KthLargestElementinanArray{
public:
    int findKthLargest(std::vector<int>& nums, int k);
    int quicksort(std::vector<int>& nums, int k, int l);
};

#endif //LECTCODE_PRACTICE_KTHLARGESTELEMENTINANARRAY_H

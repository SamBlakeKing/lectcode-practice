//
// Created by dell on 9/22/16.
//

#include "../include/KthLargestElementinanArray.h"

int KthLargestElementinanArray::quicksort(vector<int>& nums, int k, int l){
    int temp;
    while(k<l){
        while(l>k && nums[l]<= nums[k])l--;
        temp = nums[l];
        nums[l] = nums[k];
        nums[k] = temp;
        if(l == k || ++k == l)
            return l;

        while(l>k && nums[l]<=nums[k])k++;
        temp = nums[l];
        nums[l] = nums[k];
        nums[k] = temp;
        if(l == k || --l == k)
            return k;
    }

    return l;
}

int KthLargestElementinanArray::findKthLargest(vector<int>& nums, int k) {
    int s = 0;
    int e = nums.size();
    int m, l, r;
    if(e == 0) return 0;
    if(e == 1) return nums[0];


    while(1){
        m = s;
        l = e -1;
        r = quicksort(nums, m, l);
        if(r+1 == k)
            return nums[r];
        else if(r+1 < k)
            s = r+1;
        else
            e = r;
    }

    return nums[r];
}

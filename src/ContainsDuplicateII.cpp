//
// Created by tlm on 2016/11/1.
//

#include "../include/ContainsDuplicateII.h"

bool ContainsDuplicateII::containsNearbyAlmostDuplicate(vector<int>& nums, int k){
    int fast,low, t;
    fast = low = t = 0;
    while(true){
        fast = nums[nums[fast]];
        low = nums[low];
        if(fast == low)
            break;
    }
    while(true){
        low = nums[low];
        t = nums[t];
        if(t == low)break;
    }

    for(t =0; t<nums.size(); t++)
        if(t != low && nums[t] == nums[low])
            break;
    return k >= abs(low - t);

}

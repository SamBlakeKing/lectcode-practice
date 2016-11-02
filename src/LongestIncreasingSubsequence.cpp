//
// Created by tlm on 2016/10/17.
//
#include "../include/LongestIncreasingSubsequence.h"

int LongestIncreasingSubsequence::lengthOfLIS(vector<int>& nums) {
    vector<int> dp;
    for(auto i:nums){
        auto index = lower_bound(dp.begin(), dp.end(), i);
        if(index == dp.end())
            dp.push_back(i);
        else
            *index = i;
    }

    return dp.size();
}

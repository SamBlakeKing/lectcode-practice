//
// Created by tlm on 2016/10/18.
//
#include "../include/SlidingWindowMaximum.h"

vector<int> SlidingWindowMaximum::maxSlidingWindow(vector<int>& nums, int k) {
    if(nums.size() == 0 || nums.size() <k)return vector<int>();

    deque<pair<int,int>> dq;
    int curmax = INT_MIN;
    vector<int> res;
    for(int i = k-1; i>=0; i--)
        if(nums[i] > curmax) {
            dq.push_front(make_pair(i,nums[i]));
            curmax = nums[i];
        }
    for(int i=k;i<nums.size(); i++){
        res.push_back(dq.front().second);
        if(i-k == dq.front().first)
            dq.pop_front();
        while(!dq.empty() && dq.back().second <= nums[i])
            dq.pop_back();
        dq.push_back(make_pair(i,nums[i]));
    }
    res.push_back(dq.front().second);

    return res;
}
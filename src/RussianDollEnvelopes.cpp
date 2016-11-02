//
// Created by tlm on 2016/10/17.
//
#include "../include/RussianDollEnvelopes.h"

static bool envelopeCmp(const pair<int,int>&i, const pair<int,int>&j){
    if(i.first == j.first)
        return j.second < i.second;
    else
        return i.first < j.first;
}

int RussianDollEnvelopes::maxEnvelopes(vector<pair<int, int>>& envelopes) {
    vector<int> dp;
    sort(envelopes.begin(), envelopes.end(), envelopeCmp);

    for(auto i:envelopes){
        auto index = lower_bound(dp.begin(), dp.end(), i.second);
        if(index == dp.end())
            dp.push_back(i.second);
        else
            *index = i.second;
    }

    return dp.size();
}

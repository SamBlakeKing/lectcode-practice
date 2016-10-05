//
// Created by tlm on 2016/9/29.
//

#include "../include/CombinationSumII.h"

void CombinationSumII::binarySearch(vector<vector<int>> &res, vector<int>&temp, vector<int>& candidates, int i, int last){
    if(last == 0){
        res.push_back(temp);
        return;
    }else if(last < 0 || i == candidates.size())
        return;

    int n = 0;
    while(n+i < candidates.size() && candidates[i] == candidates[n+i]){
        temp.push_back(candidates[i]);
        n++;
        last -= candidates[i];
    }

    int j = n;
    for(;j>0;j--){
        binarySearch(res, temp, candidates, i+n, last);
        last += candidates[i];
        temp.pop_back();
    }
    binarySearch(res, temp, candidates, i+n, last);
}

vector<vector<int>> CombinationSumII::solution(vector<int>& candidates, int target) {
    vector<int> temp;
    vector<vector<int>> res;

    sort(candidates.begin(), candidates.end());
    binarySearch(res, temp, candidates, 0, target);

    return res;
}

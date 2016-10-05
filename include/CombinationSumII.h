//
// Created by tlm on 2016/9/29.
//

#ifndef LECTCODE_PRACTICE_COMBINATIONSUMII_H
#define LECTCODE_PRACTICE_COMBINATIONSUMII_H

#include <algorithm>
#include <vector>

using namespace std;

class CombinationSumII{
public:
    void binarySearch(vector<vector<int>> &res, vector<int>&temp, vector<int>& candidates, int i, int last);
    vector<vector<int>> solution(vector<int>& candidates, int target);
};

#endif //LECTCODE_PRACTICE_COMBINATIONSUMII_H

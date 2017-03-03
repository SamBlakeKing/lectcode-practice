//
// Created by tlm on 2016/11/2.
//

#include "../include/Fibonacci.h"

int res_num = 0;

void Fibonacci_aux(vector<int> &nums, int a, int b, int i){
    if(i == nums.size())
        return;

    if(nums[i] == b){
        res_num++;
        Fibonacci_aux(nums, b, a+b, i+1);
    }

    Fibonacci_aux(nums, a, b, i+1);
}

void Fibonacci(){
    int n, t;
    vector<int> nums;
    vector<int> res;

    cin>>n;
    for(int i=0 ;i<n; i++){
        cin>>t;
        nums.push_back(t);
    }

    Fibonacci_aux(nums, 0, 1, 0);

    cout<<res_num<<endl;
}


//
// Created by tlm on 2016/10/7.
//
#include <stack>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

int evalRPN(vector<string>& tokens) {
    int oprt1;
    int oprt2;
    stack<int> s;

    for(auto i:tokens){
        if(i == "+"){
            oprt1 = s.top();
            s.pop();
            oprt2 = s.top();
            s.pop();
            oprt1 = oprt1 + oprt2;
            s.push(oprt1);
        }else if(i == "-"){
            oprt1 = s.top();
            s.pop();
            oprt2 = s.top();
            s.pop();
            oprt1 = oprt2 - oprt1;
            s.push(oprt1);
        }else if(i == "*"){
            oprt1 = s.top();
            s.pop();
            oprt2 = s.top();
            s.pop();
            oprt1 = oprt1 * oprt2;
            s.push(oprt1);
        }else if(i == "/"){
            oprt1 = s.top();
            s.pop();
            oprt2 = s.top();
            s.pop();
            oprt1 = oprt2 / oprt1 ;
            s.push(oprt1);
        }else
            s.push(atoi((i).c_str()));
    }

    oprt1 = s.top();
    return oprt1;
}
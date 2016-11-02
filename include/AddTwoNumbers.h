//
// Created by tlm on 2016/10/5.
//

#ifndef LECTCODE_PRACTICE_ADDTWONUMBERS_H
#define LECTCODE_PRACTICE_ADDTWONUMBERS_H

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

#endif //LECTCODE_PRACTICE_ADDTWONUMBERS_H

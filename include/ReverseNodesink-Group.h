//
// Created by tlm on 2016/10/18.
//

#ifndef LECTCODE_PRACTICE_REVERSENODESINK_GROUP_H
#define LECTCODE_PRACTICE_REVERSENODESINK_GROUP_H

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class ReverseNodesinkGroup{
public:
    ListNode* reverseKGroup(ListNode* head, int k);
};

#endif //LECTCODE_PRACTICE_REVERSENODESINK_GROUP_H

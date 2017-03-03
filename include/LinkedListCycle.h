//
// Created by tlm on 2016/10/21.
//

#ifndef LECTCODE_PRACTICE_LINKEDLISTCYCLE_H
#define LECTCODE_PRACTICE_LINKEDLISTCYCLE_H

#include <iostream>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class LinkedListCycle {
public:
    bool hasCycle(ListNode *head);
    ListNode* detectCycle(ListNode *head);
};

#endif //LECTCODE_PRACTICE_LINKEDLISTCYCLE_H

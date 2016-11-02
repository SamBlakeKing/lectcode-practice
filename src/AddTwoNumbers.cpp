//
// Created by tlm on 2016/10/5.
//

#include "../include/AddTwoNumbers.h"


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *res = new ListNode(0);
    ListNode *temp = res;
    int remain = 0;

    while(l1 && l2){
        l1->val = l1->val + l2->val + remain;
        remain = l1->val /10;
        l1->val %= 10;
        temp->next = l1;
        temp = temp->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1){
        l1->val = l1->val + remain;
        remain = l1->val /10;
        l1->val %= 10;
        temp->next = l1;
        temp = temp->next;
        if(remain == 0)
            break;
        l1 = l1->next;
    }
    while(l2){
        l2->val = l2->val + remain;
        remain = l2->val /10;
        l2->val %= 10;
        temp->next = l2;
        temp = temp->next;
        if(remain == 0)
            break;
        l2 = l2->next;
    }
    if(remain){
        temp->next = new ListNode(remain);
    }
    temp = res->next;
    delete res;

    return temp;
}

//
// Created by tlm on 2016/10/21.
//


#include "../include/LinkedListCycle.h"

// Linked List cycle I
bool LinkedListCycle::hasCycle(ListNode *head) {
    ListNode *first, *second;
    if(head == NULL)
        return false;
    first = head->next;
    second = head;
    while(first){
        if(first == second)
            return true;
        if(first->next)
            first = first->next->next;
        else
            first = first->next;
        second = second->next;
    }

    return false;
}

ListNode *LinkedListCycle::detectCycle(ListNode *head) {
    ListNode *first, *second;
    if(head == NULL || head->next == NULL || head->next->next == NULL)
        return 0;
    if(head->next->next == head)
        return head;

    first = head->next;
    second = head;
    while(first){
        if(first == second)
            break;
        if(first->next)
            first = first->next->next;
        else
            first = first->next;
        second = second->next;
    }
    cout<<first->val<<endl;
    cout<<second->val<<endl;
    if(first != second)
        return 0;

    second = head;
    while(first != second){
        first = first->next;
        second = second->next;
    }

    return first;
}
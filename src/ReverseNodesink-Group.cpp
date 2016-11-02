//
// Created by tlm on 2016/10/18.
//
#include "../include/ReverseNodesink-Group.h"

ListNode* ReverseNodesinkGroup::reverseKGroup(ListNode* head, int k) {
    if(head==NULL || k == 0)
        return head;

    int i = 0;
    ListNode *h,*t=NULL,*p, *n;
    ListNode *t_head = new ListNode(0);
    h = t_head;
    p = head;

    while(p){
        if(t == NULL){
            h->next = p;
            t = p;
            p = p->next;
            h->next->next = NULL;
        }else{
            n = p->next;
            p->next = h->next;
            h->next = p;
            p = n;
        }
        i++;
        if(i==k){
            i = 0;
            h = t;
            t = NULL;
        }
    }

    if(i != 0){
        p = h->next->next;
        h->next->next = NULL;
        while(p){
            n = p->next;
            p->next = h->next;
            h->next = p;
            p = n;
        }
    }

    p = t_head->next;
    delete t_head;
    return p;
}
//
// Created by tlm on 2016/9/30.
//
#include "../include/shortestPath.h"

struct Node{
    int e;
    long length;
    Node *next;
    Node():e(0),length(0),next(NULL){}
};

int shortestPath(){
    int a, b, l;
    int N, M, S, T;
    cin>>N>>M>>S>>T;
    Node *p;

    Node *list = new Node[N];
    int *res = new int[N];
    int *checked = new int[N];
    for(int i=0; i<N;i++){
        checked[i] = 0;
        list[i].next = NULL;
    }


    for(int i=0; i<N; i++)
        res[i] = INT_MAX;

    for(int i=0; i<M;i++){
        p = new Node;
        cin>>a>>b>>l;

        p->next = list[a-1].next;
        p->e = b-1;
        p->length = l;
        list[a-1].next = p;

        p = new Node;
        p->next = list[b-1].next;
        p->e = a-1;
        p->length = l;
        list[b-1].next = p;
    }

    res[S-1] = 0;
    for(int j= 1;j<N;j++){
        b = 0;
        a = INT_MAX;
        for(int i=0; i<N;i++)
            if(checked[i] == 0 && a > res[i]){
                a = res[i];
                b = i;
            }

        while(list[b].next){
            p = list[b].next;
            list[b].next = p->next;
            if(res[p->e] > p->length + res[b])
                res[p->e] = p->length + res[b];
            delete p;
        }
        checked[b] = 1;
    }

    delete[] list;
    delete[] res;
    delete[] checked;

    cout<<res[T-1];
    return 0;
}

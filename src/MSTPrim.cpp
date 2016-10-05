//
// Created by dell on 9/25/16.
//

#include "../include/MSTPrim.h"

struct Node{
    int s;
    int e;
    int dist;
    Node(){};
};

int cmp(const void *_a, const void *_b){
    Node *a = (Node *)_a;
    Node *b = (Node *)_b;
    return a->dist > b->dist;
}

int findP(int x, int *p){
    return p[x] == x ? x: findP(p[x], p);
}

int func(int N, int *dist){
    int m = N * (N-1);
    Node *nodes = new Node[m];
    int n = 0;
    int *p = new int[N];
    int ans = 0;
    int k;

    for(int i=1;i<N;i++)
        for(int j=0;j<i;j++){
            nodes[n].s = i;
            nodes[n].e = j;
            k = i * N + j;
            nodes[n].dist = dist[k];
            n++;
        }
    qsort(nodes, m, sizeof(Node), cmp);

    for(int i=0; i<N; i++)
        p[i] = i;

    for(int i=0; i<m;i++){
        int x = findP(nodes[i].s, p);
        int y = findP(nodes[i].e, p);

        if(x != y){
            ans += nodes[i].dist;
            p[x] = y;
        }
    }

    delete []p;
    delete []nodes;

    return ans;
}

int MSTPrim(void){
    int N;
    int *dist;

    while(std::cin>>N){
        dist = new int[N*N];

        for(int i=0; i< N *N; i++)
            std::cin>>dist[i];


        std::cout<<func(N, dist)<<std::endl;


        delete []dist;
    }

    return 0;
}

//
// Created by tlm on 2016/10/18.
//

#include "../include/EditDistance.h"

int EditDistance::minDistance(string word1, string word2) {
    int m = word1.size(), n= word2.size();
    if(m == 0)
        return n;
    if(n == 0)
        return m;

    int **m_length =  new int*[m+1];
    for(int i=0; i<m+1; i++)
        m_length[i] = new int[n+1];
    for(int i=0; i<m+1; i++)
        m_length[i][n] = m-i;
    for(int i=0; i<n+1; i++)
        m_length[m][i] = n-i;

    int temp;
    for(int i=n-1; i>=0; i--)
        for(int j= m-1; j>=0; j--){
            if(word1[j] == word2[i])
                m_length[j][i] = m_length[j+1][i+1];
            else{
                temp = min(m_length[j+1][i+1], m_length[j][i+1]);
                temp = min(temp, m_length[j+1][i]);
                m_length[j][i] = temp + 1;
            }
        }

    return m_length[0][0];
}

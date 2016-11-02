//
// Created by tlm on 2016/10/18.
//

#ifndef LECTCODE_PRACTICE_DISTINCTSUBSEQUENCES_H
#define LECTCODE_PRACTICE_DISTINCTSUBSEQUENCES_H

#include <iostream>
#include <cstring>
using namespace std;

class DistinctSubsequences {
public:
    int numDistinct(string s, string t) {
        if(s.size() == 0 || t.size() == 0 || s.size() < t.size())
            return 0;

        int n = s.size(), m = t.size();
        int **max_change = new int*[n];
        for(int i=0;i<n;i++){
            max_change[i] = new int[m];
            memset(max_change[i], 0, m* sizeof(int));
        }

        if(s[0] == t[0])
            max_change[0][0] = 1;
        else
            max_change[0][0] = 0;
        for(int i=1;i<m;i++)
            if(s[i] == t[i])
                max_change[i][i] = max_change[i-1][i-1];
            else
                max_change[i][i] = max_change[i-1][i];
        for(int j=0;j<m;j++)
            for(int i=j+1; i<n; i++){
                max_change[i][j] = max_change[i-1][j];
                if(s[i] == t[j])
                    max_change[i][j] += (j-1 < 0?1:max_change[i-1][j-1]);
            }

        return max_change[n-1][m-1];
    }
};

#endif //LECTCODE_PRACTICE_DISTINCTSUBSEQUENCES_H

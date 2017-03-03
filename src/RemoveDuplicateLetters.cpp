//
// Created by tlm on 2016/11/3.
//

#include "../include/RemoveDuplicateLetters.h"

string RemoveDuplicateLetters::removeDuplicateLetters(string s){
    int nums[26];
    queue<char> q;

    memset(nums, 0 , 26*sizeof(int));

    char *res = new char[s.size()];
    for(int i=0; i<s.size(); i++)
        nums[s[i] - 'a']++;

    int k, j=0;
    for(k=0; k<26; k++)
        if(nums[k])break;

    for(int i=0; i<s.size(); i++){
        if(s[i] - 'a' == k){
            res[j++] = s[i];
            while(!q.empty()){
                if(nums[q.front() - 'a']){
                    res[j++] = q.front();
                    nums[q.front() - 'a'] = 0;
                }
                q.pop();
            }
            nums[s[i] - 'a' ] = 0;
            while(k<26){
                if(nums[k])
                    break;
                k++;
            }
        }else if(s[i] - 'a' > k){
            q.push(s[i]);
            nums[s[i]-'a']--;
        }

    }
    res[j] = '\0';

    return res;
}

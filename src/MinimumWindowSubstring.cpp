//
// Created by tlm on 2016/10/19.
//

#include "../include/MinimumWindowSubstring.h"

string minWindow(string s, string t){
    int char_num[26];
    int cur_begin = 0, cur_end = 0;
    int cur_max_begin = 0, cur_max_end = 0;
    unsigned int c_t = 0;
    queue<int> cur_char;

    for(int i=0; i<26; i++)
         char_num[i] = -1;
    for(int i=0; i<t.size(); i++){
        char_num[t[i] - 'A'] = 0;
        c_t = c_t | ( 1<<(t[i] - 'A'));
    }

    unsigned int temp = 0;
    while(cur_end <s.size()){
        if(c_t & (1<<(s[cur_end] - 'A')) ){
            cur_char.push(cur_end);
            temp = temp | (1<<(s[cur_end] - 'A'));
            char_num[s[cur_end] - 'A']++;
            if(temp == c_t)
                break;
        }
        cur_end++;
    }


}



//
// Created by tlm on 2016/9/28.
//
#include "../include/GroupAnagrams.h"

typedef multimap<string,string,less<string> >::value_type vt;

//string translateString(string a){
//    int n=0;
//    char *temp = new char[a.size()+1];
//    multiset<char, less<char>> b;
//    for(int j = 0; j<a.size(); j++)
//        b.insert(a[j]);
//
//    for(auto i=b.begin(); i != b.end(); i++)
//        temp[n++] = *i;
//
//    temp[n] = '\0';
//    return temp;
//}


vector<vector<string>> GroupAnagrams::solution(vector<string>& strs) {
    multimap<string,string> tempMap;
    vector<vector<string>> res;
    vector<string> temp;
    string key;

    for(auto i = strs.begin(); i != strs.end(); i++){
        key = *i;
        sort(key.begin(),key.end());
        tempMap.insert(vt(key, *i));
    }

    auto i = tempMap.begin();
    string first = (*i).first;
    for(;i!=tempMap.end();)
        if((*i).first == first){
            temp.push_back((*i).second);
            i++;
        }
        else{
            res.push_back(temp);
            temp.assign(1, (*i).second);
//            temp.clear();
//            temp.push_back((*i).second);
            first = (*i).first;
            i++;
        }
    if (temp.size())
        res.push_back(temp);

    return res;
}

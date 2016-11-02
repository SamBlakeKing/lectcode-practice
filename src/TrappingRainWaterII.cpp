//
// Created by tlm on 2016/10/17.
//

#include "../include/TrappingRainWaterII.h"

int TrappingRainWaterII::trapRainWater(vector<vector<int>>& heightMap){
    if(heightMap.size() == 0 || heightMap[0].size() == 0)return 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> que;
    int n = heightMap.size();
    int m = heightMap[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            if(!(i==0 || i == n-1 || j==0 || j==m-1))continue;
            que.push(make_pair(heightMap[i][j], i*m+j));
            visited[i][j] = 1;
        }

    int res = 0;
    int max_height = INT_MIN;
    int i, j, height;
    vector<pair<int,int>> pos = {{0, 1}, {0, -1}, {1, 0}, {-1,0}};
    while(!que.empty()){
        auto p = que.top();
        que.pop();
        height = p.first;
        i = p.second / m;
        j = p.second % m;

        max_height = max(max_height, height);
        for(auto q:pos){
            if(i+q.first < 0 || i+q.first >= n || j+q.second<0 ||
                    j+q.second>= m || visited[i+q.first][j+q.second])
                continue;
            height = heightMap[i+q.first][j+q.second];
            if(max_height > height) res += (max_height - height);
            que.push(make_pair(height, (i+q.first)*m+j+q.second));
            visited[i+q.first][j+q.second] = 1;
        }
    }

    return res;
}

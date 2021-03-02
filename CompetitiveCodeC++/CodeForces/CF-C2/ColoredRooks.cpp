#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> ans[101];
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i<=n; i++){
        ans[i].push_back({i, i});
    }

    int currX = n+1;
    for(int i = 0; i<m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        ans[a].push_back({currX, a});
        ans[b].push_back({currX, b});
        currX++;
    }

    for(int i = 1; i<=n; i++){
        printf("%d\n", ans[i].size());
        for(auto j: ans[i]){
            printf("%d %d\n", j.first, j.second);
        }
    }
}
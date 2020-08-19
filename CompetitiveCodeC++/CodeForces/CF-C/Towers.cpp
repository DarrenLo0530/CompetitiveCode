#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> towers;
vector<pair<int, int>> ans;

int main(){
    int n, k;
    scanf("%d%d", &n, &k);

    for(int i = 1; i <= n; i++){
        int a;
        scanf("%d", &a);
        towers.push_back({a, i});
    }

    int s;
    int m = k;
    for(int i = 0; i<k; i++){

        sort(towers.begin(), towers.end());
        s = towers.back().first - towers.front().first;
        if(towers.front().first == towers.back().first){
            m = i;
            break;
        }

        towers.front().first++;
        towers.back().first--;
        pair<int, int> op = {towers.back().second, towers.front().second};
        ans.push_back(op);
    }

    sort(towers.begin(), towers.end());
    s = towers.back().first - towers.front().first;

    printf("%d %d\n", s, m);
    for(int i = 0; i<m; i++){
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
}
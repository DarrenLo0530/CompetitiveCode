#include <bits/stdc++.h>
using namespace std;
int p[50001][3];

int solve(vector<int> idx, int d){
    if(d == 3){ //In 0 dimension so always unique coord
        return idx[0];
    }

    map<int, vector<int>> mp;
    //Map dimension's coordinate to index
    for(int i: idx){
        mp[p[i][d]].push_back(i);
    }

    vector<int> ans;
    //For each dimension coordinate with atleast one point
    for(auto it = mp.begin(); it != mp.end(); it++){
        int ret = solve(it->second, d+1);
        if(ret != -1){
            ans.push_back(ret);
        }
    }

    for(int i = 1; i<ans.size(); i+=2){
        printf("%d %d\n", ans[i]+1, ans[i-1]+1);
    }
    if(ans.size() % 2 != 0){
        return ans.back();
    }

    return -1;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<3; j++){
            scanf("%d", &p[i][j]);
        }
    }

    vector<int> init;
    for(int i = 0; i<n; i++){
        init.push_back(i);
    }
    solve(init, 0);

}
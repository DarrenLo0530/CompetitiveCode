#include <bits/stdc++.h>
using namespace std;

int hasCat[100005];
vector<int> adj[100005];
int n, m;

int dfs(int prevCat, int curr, int par){
    int currCat = prevCat;
    if(hasCat[curr]){
        currCat++;
    } else {
        currCat = 0;
    }

    if(currCat > m){
        return 0;
    }

    if(adj[curr].size() == 1 && adj[curr][0] == par){
        return 1;
    }

    int rest = 0;
    for(int i: adj[curr]){
        if(i != par){
            rest += dfs(currCat, i, curr);
        }
    }

    return rest;
}

int main(){
    scanf("%d%d", &n,&m);

    for(int i = 1; i<=n; i++){
        scanf("%d", hasCat + i);
    }

    for(int i = 0; i<n-1; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout<<dfs(0, 1, -1)<<'\n';
}
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[51];
bool vis[51];

bool dfs(int curr, int dest, int exclude){
    if(curr == dest){
        return true;
    }
    
    vis[curr] = true;
    
    for(pair<int, int> i: adj[curr]){
        if(!vis[i.first] && i.second != exclude ){
            if(dfs(i.first, dest, exclude)){
                return true;
            }
        }
    }

    return false;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    
    for(int i = 0; i<m; i++){
        int s, t;
        scanf("%d%d", &s, &t);
        
        adj[s].push_back({t, i});
    }
    
    for(int i = 0; i<m; i++){
        memset(vis, false, sizeof(vis));
        if(dfs(1, n, i)){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    
}
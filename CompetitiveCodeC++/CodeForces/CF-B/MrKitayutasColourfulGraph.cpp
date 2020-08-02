#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101][101];

bool visited[101];
bool dfs(int colour, int curr, int par, int search){
    visited[curr] = true;
    if(curr == search){
        return true;
    }

    for(int i: adj[colour][curr]){
        if(!visited[i] && i != par){
            if(dfs(colour, i, curr, search)){
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
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[c][a].push_back(b);
        adj[c][b].push_back(a);
    }

    int q;
    scanf("%d", &q);

    for(int i = 0; i<q; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        int ans = 0;
        for(int c = 1; c<=100; c++){
            memset(visited, false, sizeof(visited));
            if(dfs(c, u, -1, v)){
                ans++;
            }
        }

        printf("%d\n", ans);
    }
}
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[150001];
bool visited[150001];
long long nodes = 0, edges = 0;

void dfs(int curr){
    visited[curr] = true;
    nodes++;
    for(int j: adj[curr]){
        edges++;
        if(!visited[j]){
            dfs(j);
        }
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i<=n; i++){
        if(!visited[i]){
            nodes = 0;
            edges = 0;
            dfs(i);
            if(nodes * (nodes-1) != edges){
                printf("NO\n");
                return 0;
            }
        }
    }

    printf("YES\n");
}
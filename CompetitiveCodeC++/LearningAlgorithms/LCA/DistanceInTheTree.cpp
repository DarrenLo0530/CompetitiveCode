#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

vector<pii> adj[50001];
int par[50001][21], dist[50001][21], depth[50001];
void dfs(int curr, int parent, int prevDist, int d){
    dist[curr][0] = prevDist;
    par[curr][0] = parent;
    depth[curr] = d;
    
    for(int i = 1; i<=20; i++){
        if(par[par[curr][i-1]][i-1] != 0){
            par[curr][i] = par[par[curr][i-1]][i-1];
            dist[curr][i] = dist[curr][i-1] + dist[par[curr][i-1]][i-1];
        }
    }

    for(pii i: adj[curr]){
        if(i.first != parent){
            dfs(i.first, curr, i.second, d+1);
        }
    }
}

int lca(int a, int b){
    if(depth[b] > depth[a]){
        swap(a, b);
    }

    for(int i = 20; i >= 0; i--){
        if(par[a][i] && depth[par[a][i]] >= depth[b]){
            a = par[a][i];
        }
    }

    if(a == b){
        return b;
    }

    for(int i = 20; i>=0; i--){
        if(par[a][i] != par[b][i]){
            a = par[a][i];
            b = par[b][i];
        }
    }

    return par[a][0];
}

int solve(int a, int b){
    int l = lca(a, b);
    int totalDist = 0;
    
    for(int i = 20; i>=0; i--){
        if(par[a][i] && depth[par[a][i]] >= depth[l]){
            totalDist += dist[a][i];
            a = par[a][i];
        }

        if(par[b][i] && depth[par[b][i]] >= depth[l]){
            totalDist += dist[b][i];
            b = par[b][i];
        }
    }

    return totalDist;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n-1; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u++, v++;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs(1, 0, 0, 0);

    int q;
    scanf("%d", &q);
    
    for(int i = 0; i<q; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        u++, v++;

        printf("%d\n", solve(u, v));
    }
    
}
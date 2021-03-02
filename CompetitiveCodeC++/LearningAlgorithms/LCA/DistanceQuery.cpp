#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

vector<pii> adj[100001];
int binaryLifting[100001][17], mx[100001][17], mn[100001][17];
int depth[100001];

void dfs(int curr, int par, int inc, int d){
    binaryLifting[curr][0] = par;
    if(par != 0){
        mx[curr][0] = inc;
        mn[curr][0] = inc;
    }
    depth[curr] = d;

    for(int i = 1; i<=16; i++){
        if(binaryLifting[curr][i-1] != 0){
            binaryLifting[curr][i] = binaryLifting[binaryLifting[curr][i-1]][i-1];
            mx[curr][i] = max(mx[curr][i-1], mx[binaryLifting[curr][i-1]][i-1]);
            mn[curr][i] = min(mn[curr][i-1], mn[binaryLifting[curr][i-1]][i-1]);
        }
    }

    for(pii i: adj[curr]){
        if(i.first != par){
            dfs(i.first, curr, i.second, d+1);
        }
    }
}

int lca(int a, int b){
    if(depth[a] < depth[b]){
        swap(a, b);
    }

    for(int i = 16; i>=0; i--){
        if(binaryLifting[a][i] != 0 && depth[binaryLifting[a][i]] >= depth[b]){
            a = binaryLifting[a][i];
        }
    }

    if(a == b){
        return b;
    }

    for(int i = 16; i>=0; i--){
        int aPar = binaryLifting[a][i];
        int bPar = binaryLifting[b][i];
        if(aPar != bPar){
            a = aPar;
            b = bPar;
        }
    }

    return binaryLifting[a][0];
}

void solve(int a, int b){
    int dest = lca(a, b);
    pii ans = {INF, -INF};
    for(int i = 16; i>=0; i--){
        if(binaryLifting[a][i] != 0 && depth[binaryLifting[a][i]] >= depth[dest]){
            ans.first = min(ans.first, mn[a][i]);
            ans.second = max(ans.second, mx[a][i]);
            a = binaryLifting[a][i];
        }

        if(binaryLifting[b][i] != 0 && depth[binaryLifting[b][i]] >= depth[dest]){
            ans.first = min(ans.first, mn[b][i]);
            ans.second = max(ans.second, mx[b][i]);
            b = binaryLifting[b][i];
        }
    }

    printf("%d %d\n", ans.first, ans.second);
}

int main(){
    memset(mn, INF, sizeof(mn));
    memset(mx, -INF, sizeof(mx));
    int n;  
    scanf("%d", &n);
    int a, b, c;
    for(int i = 0; i<n-1; i++){
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    dfs(1, 0, 0, 0);

    int q;
    scanf("%d", &q);
    for(int i = 0; i<q; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        solve(a, b);
    }
    
}
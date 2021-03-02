#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int guard[500001];
set<int> al[500001];
vector<int> adj[500001];
set<int> can;

bool dfs(int curr, int par, int alien, bool passed, int u){
    if(curr == u){
        passed = true;
    }

    if(passed){
        can.insert(guard[curr]);
    }

    bool ans = false;
    for(int i: adj[curr]){
        if(i != par){
            ans |= dfs(i, curr, alien, passed, u);
        }
    }

    return ans;
}

int main(){
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);

    for(int i = 1; i<=n; i++){
        int x;
        scanf("%d", &x);
        guard[i] = x;
        al[x].insert(i);
    }

    for(int i = 0; i<n-1; i++){
        int a, b;
        scanf("%d%d", &a, &b);

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i<m; i++){
        int o;
        scanf("%d", &o);

        if(o == 1){
            int c, k;
            scanf("%d%d", &c, &k);
            al[guard[c]].erase(k);
            guard[c] = k;
            al[k].insert(c);
        } else {
            can.clear();
            int u;
            scanf("%d", &u);
            int ans = 0;
            dfs(1, -1, i, false, u);
            printf("%d\n", can.size());
        }
    }
}

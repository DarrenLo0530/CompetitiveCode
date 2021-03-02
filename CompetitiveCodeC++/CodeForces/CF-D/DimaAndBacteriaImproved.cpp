#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int MX = 501;
const int UP = 1e5+10;
int td[MX][MX];
vector<pii> adj[UP];
vector<pii> adj2[UP];


int c[MX];
int type[UP];
bool vis[UP];

int dfs(int x, int t) {
    int cnt = type[x] == t ? 1 : 0;
    for(pii i: adj[x]) {
        if(!vis[i.first] && !i.second) {
            vis[i.first] = true;
            cnt += dfs(i.first, t);
        }

    }

    return cnt;
}

int main(){
    memset(td, INF, sizeof(td));
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    for(int i =1; i<=k; i++) {
        scanf("%d", &c[i]);
        c[i] += c[i-1];
        type[c[i] + 1] = 1;
    }


    type[0] = 1;

    for(int i = 1; i<=n; i++) {
        type[i] += type[i-1];
    }

    for(int i =0 ; i<m; i++) {
        int u, v, x;
        scanf("%d%d%d",  &u, &v, &x);
        adj[u].push_back({v, x});
        adj[v].push_back({u, x});
    }

    for(int i = 1; i<=n; i++) {
        for(pii j: adj[i]) {
            td[type[i]][type[j.first]] = min(td[type[i]][type[j.first]], j.second);
            td[type[j.first]][type[i]] = min(td[type[j.first]][type[i]], j.second);

        }
    }

    for(int i = 1; i<=k; i++) {
        memset(vis, false, sizeof(vis));
        vis[c[i]] = true;
        if(dfs(c[i], i) != (c[i] - c[i-1])) {
            printf("No\n");
            return 0;
        }
    }

    for(int i = 1; i<=k; i++) {
        td[i][i] = 0;
    }
    
    for(int i = 1; i<=k; i++) {
        for(int j = 1; j<=k; j++) {
            for(int l = 1; l<=k; l++) {
                td[j][l] = min(td[j][l], td[j][i] + td[i][l]);
            }
        }
    }

    printf("Yes\n");

    for(int i = 1; i<=k; i++) {
        for(int j = 1; j<=k; j++) {
            if(td[i][j] == INF) {
                td[i][j] = -1;
            }

            if(j != 1) {
                printf(" %d", td[i][j]);
            } else {
                printf("%d", td[i][j]);
            }
        }
        printf("\n");
    }

    

    
}
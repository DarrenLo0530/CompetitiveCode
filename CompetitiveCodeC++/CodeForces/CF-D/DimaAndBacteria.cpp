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
int c[MX];
vector<pii> adj[UP];
vector<pii> adj2[UP];

int type[UP];

int cost[UP];
bool vis[UP];

/*
This solves it if you need to find the 2D array answer no matter if the thing is correct
Downside is ihat it is ELogV which seems to be too slow...
*/

int dfs(int x, int t) {
    int cnt = type[x] == t ? 1 : 0;
    for(pii i: adj2[x]) {
        if(!vis[i.first]) {
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

        if(x == 0) {
            adj2[u].push_back({v, x});
            adj2[v].push_back({u, x});
        }
    }

    for(int t = 1; t<=k; t++) {
        memset(cost, INF, sizeof(cost));

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(int curr = c[t-1] + 1; curr<=c[t]; curr++) {
            pq.push({0, curr});
            cost[curr] = 0;
        }

        while(!pq.empty()) {
            int dist = pq.top().first;
            int curr = pq.top().second;
            
            pq.pop();

            if(cost[curr] < dist) {
                continue;
            }

            for(pii i: adj[curr]) {
                int next = i.first;

                if(i.second + dist < cost[next]) {
                    cost[next] = i.second + dist;
                    pq.push({cost[next], next});
                }
            }
        }

        for(int i = 1; i<=n; i++) {
            td[t][type[i]] = min(td[t][type[i]], cost[i]);
        }
    }


    for(int i = 1; i<=k; i++) {
        memset(vis, false, sizeof(vis));
        vis[c[i]] = true;
        if(dfs(c[i], i) != c[i] - c[i-1]) {
            printf("No\n");
            return 0;
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
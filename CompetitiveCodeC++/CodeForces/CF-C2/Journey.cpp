#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const int MX = 5005;
vector<pii> adj[MX];

int n, m, T;
int dp[MX][MX];
int backTrack[MX][MX];
bool visited[MX];

void solve(int curr){
    visited[curr] = true;

    if(curr == n){
        dp[curr][1] = 0;
        backTrack[curr][1] = -1;
    }

    for(pii i: adj[curr]){
        if(!visited[i.first]){
            solve(i.first);
        }
        for(int numVisited = 0; numVisited <= n; numVisited++){
            if(dp[i.first][numVisited] + i.second < dp[curr][numVisited+1]){
                dp[curr][numVisited+1] = dp[i.first][numVisited] + i.second;
                backTrack[curr][numVisited + 1] = i.first;
            }
        }
        
    }
}

int main(){
    scanf("%d%d%d", &n, &m, &T);
    for(int i = 0; i<m; i++){
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        adj[u].push_back({v, t});
    }
    memset(dp, INF, sizeof(dp));

    solve(1);
    int ans = 0;
    for(int i = 5000; i>=0; i--){
        if(dp[1][i] <= T){
            ans = i;
            break;
        }
    }

    vector<int> path;
    int curr = 1;
    for(int numRemaining = ans; numRemaining >= 1; numRemaining--){
        path.push_back(curr);
        curr = backTrack[curr][numRemaining];
    }

    printf("%d\n", ans);
    for(int i = 0; i<path.size(); i++){
        if(i != 0){
            printf(" ");
        }
        printf("%d", path[i]);
    }

    printf("\n");
}
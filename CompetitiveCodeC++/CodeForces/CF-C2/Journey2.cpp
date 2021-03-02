#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

vector<int> adj[100001];
ld dfs(int curr, int par, int dist){
    if(adj[curr].size() == 1){
        return dist;
    }

    ld prob = 1.0/(ld)(adj[curr].size()-1);
    ld ev = 0;
    
    for(int i: adj[curr]){
        if(i != par){
            ev += dfs(i, curr, dist+1)*prob;
        }
    }

    return ev;

}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n-1; i++){
        int s, e;
        scanf("%d%d", &s, &e);
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    adj[1].push_back(-1);
    ld ans = dfs(1, -1, 0);
    cout << fixed << setprecision(15) << ans << '\n';
}
#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

vector<int> adj[10001];
pii dfs(int curr, int par, int dist){
    pii ret = {curr, dist};
    for(int i: adj[curr]){
        if(i != par){
            pii child = dfs(i, curr, dist+1);
            if(child.second > ret.second){
                ret = child;
            }
        }
    }

    return ret;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n-1; i++){
        int u,v ;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    pii first = dfs(1, -1, 0);
    pii second = dfs(first.first, -1, 0);
    printf("%d\n", second.second);


}
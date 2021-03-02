#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

vector<pii> adj[10001];

pii dfs(int curr, int par, int dist){
    pii mx = {curr, dist};
    for(pii i: adj[curr]){
        if(i.first != par){
            pii next = dfs(i.first, curr, dist + i.second);
            if(next.second > mx.second){
                mx = next;
            }
        }
    }
    
    return mx;

}

void solve(){
    int leaf = dfs(1, -1, 0).first;
    int ans = dfs(leaf, -1, 0).second;
    printf("%d\n", ans);
    for(int i = 0; i<=10000; i++){
        adj[i].clear();
    }
}
int main(){
    //freopen("input.txt", "r", stdin);

    string s;
    while(getline(cin, s)){
        if(s.empty()){
            solve();
        } else {
            stringstream ss(s);
            int a, b, c;
            while(ss >> a >> b >> c){
                adj[a].push_back({b, c});
                adj[b].push_back({a, c});
            }
        }
    }

    solve();
}
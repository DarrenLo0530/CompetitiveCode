#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int c[101];
int inDeg[101];
bool vis[101];

ll lcm(ll a, ll b){
    return a * b / __gcd(a, b);
}
int dfs(int curr, int len){
    if(vis[curr]){
        return len;
    }

    vis[curr] = true;
    return dfs(c[curr], len + 1);
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        scanf("%d", c + i);
        if(inDeg[c[i]] >= 1){
            printf("-1\n");
            return 0;
        }
        inDeg[c[i]]++;
    }

    ll ans = 1;
    for(int i = 1; i<=n; i++){
        if(!vis[i]){
            int len = dfs(i, 0);
            if(len % 2 == 0){
                ans = lcm(ans, len/2);
            } else {
                ans = lcm(ans, len);
            }
        }

    }

    cout << ans << "\n";

}   
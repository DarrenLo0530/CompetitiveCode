#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

ll nk[1005][1005];
ll tp[1005];
const int md = 1e9 + 7;
void fill(){
    nk[0][0] = 1;
    for(int i = 1; i<=1000; i++){
        nk[i][0] = 1;
        for(int j = 1; j<=i; j++){
            nk[i][j] = (nk[i-1][j-1] + nk[i-1][j]) % md;
        }
    }
    tp[0] = 1;
    for(int i = 1; i<=1000; i++){
        tp[i] = (tp[i-1] * 2) % md;
    }
}
int main(){
    fill();
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> t;

    for(int i = 0; i<m; i++){
        int x;
        scanf("%d", &x);
        t.push_back(x);
    }
    t.push_back(n+1);
    sort(t.begin(), t.end());

    int numLights = 0;
    ll ans = 1;
    for(int i = 0; i<m+1; i++){
        if(i == 0){
            numLights = t[i]-1;
        } else {
            int numNew = t[i] - t[i-1] - 1;
            ans = (ans * nk[numLights + numNew][numLights]) % md;
            if(i != m){
                ans = (ans * tp[max(0, numNew-1)]) % md;
            }
            numLights += numNew;
        }
    }

    printf("%lld\n", ans);
    
}
#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const int m = 998244353;

ll nk[5001][5001];

ll fact[5001];

void factGen(){
    fact[0] = 1;
    for(int i = 1; i<=5000; i++){
        fact[i] = (fact[i-1] * i) % m;
    }
}

void fix(){
    nk[0][0] = 1;

    for(int i = 1; i<=5000; i++){
        nk[i][0] = 1;
        for(int j = 1; j<=i; j++){
            nk[i][j] = (nk[i-1][j-1] + nk[i-1][j]) % m;
        }
    }
}

ll solve(int r, int b){
    ll ans = 0;
    for(int i = 0; i<=min(r,b); i++){
        ll num = ((nk[r][i] * nk[b][i]) % m * fact[i]) % m;
        ans = (ans + num) % m;
    }
    return ans;
}



int main(){
    fix();
    factGen();

    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    ll ans = 1;
    ans = ans * solve(a, b) % m;
    ans = ans * solve(b, c) % m;
    ans = ans * solve(a, c) % m;
    
    

    printf("%lld\n", ans);
}
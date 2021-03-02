#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

ll child[1000001];
int m = 1e9 + 7;

int main(){
    ll n, k, t, c;
    scanf("%lld%lld%lld%lld", &n, &k, &t, &c);
    
    ll ads = c;

    for(int i = 1; i<=n-1; i++){
        child[i] = (ads*k) % m;
        if(i-t >= 1){
            ads = (ads + child[i-t]) % m;
            child[i-t] = 0;
        }
    }


    ll ans = 0;
    for(int i = 1; i<n; i++){
        ans = (ans + child[i]) % m;
    }

    ans = (ans % m + ads * 2) % m;
    printf("%lld\n", ans);


}
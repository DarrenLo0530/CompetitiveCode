#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int md = 1e9 + 9;

ll modExpo(ll b, ll e){
    ll ans = 1;
    while(e != 0){
        if(e % 2 != 0){
            ans = (ans * b) % md;
        } 
        b = (b * b) % md;
        e/=2;
    }

    return ans;
}

int main(){
    ll n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    ll numMultiplier = n/k;
    ll ans = 0;

    if(n - numMultiplier >= m){
        ans = m % md;
    } else {
        ll numExtra = m - (n - numMultiplier);
        ans = ((2*(modExpo(2, numExtra) -1)*k)% md + (n - numMultiplier - (k-1)*numExtra) % md ) % md;
    }

    printf("%lld\n", ans % md);

    


}
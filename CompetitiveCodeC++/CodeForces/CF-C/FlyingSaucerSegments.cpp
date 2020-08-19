#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll modExpo(ll b, ll m, ll p){
    ll ret = 1;
    while(p > 0){
        if(p % 2 != 0){
            ret = (ret * b) % m;
        }

        b = (b * b) % m;
        p /= 2;
    }

    return ret;
}

int main(){
    ll n, m;
    scanf("%lld%lld", &n, &m);
    ll ans = (modExpo(3, m, n) - 1 + m) % m;
    cout<<ans<<'\n';
}
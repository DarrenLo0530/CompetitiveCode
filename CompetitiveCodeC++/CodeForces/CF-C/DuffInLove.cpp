#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll x;
    scanf("%lld", &x);
    ll ans = 1;
    set<ll> factors;

    for(ll i = 2; i<sqrt(x)+1; i++){
        while(x % i == 0){
            x /= i;
            factors.insert(i);
        }
    }

    factors.insert(x);
    for(ll i: factors){
        ans *= i;
    }

    cout<<ans<<'\n';
}
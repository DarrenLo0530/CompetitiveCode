#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll m = 1e9 + 7;
ll modExpo(ll x, ll n, ll mod = m){
    ll res = 1;
    
    while(n){
        if(n % 2 != 0){
            res = ((__int128)res * x) % mod;
        }

        n/=2;
        x = ((__int128)x * x) % mod;
    }
    return res;
}


int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        ll a, b, n;
        scanf("%lld%lld%lld", &a, &b, &n);

        ll right = a - b;
        if(right == 0){
            cout<< (modExpo(a, n) + modExpo(b, n)) % m << '\n';
        } else {
            ll left = (modExpo(a, n, right) + modExpo(b, n, right)) % right;
            ll ans = __gcd(left , right) % m;
            cout<<ans<<'\n';
        }        
    }

}
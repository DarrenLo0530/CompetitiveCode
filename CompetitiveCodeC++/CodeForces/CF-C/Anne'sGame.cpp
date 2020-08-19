#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 2000000011;
ll modExpo(ll a, ll b, ll m){
    ll res = 1;
    while(b){
        if(b % 2 != 0){
            res = (res * a) % m;
        }

        b /= 2;
        a = (a * a) % m;
    }

    return res;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        ll ans;
        int k;
        scanf("%d", &k);
        if(k <= 1){
            ans = 1;
        } else {
            ans = modExpo(k, k-2, MOD);
        }

        printf("Case #%d: %lld\n", i, ans);
    }
}
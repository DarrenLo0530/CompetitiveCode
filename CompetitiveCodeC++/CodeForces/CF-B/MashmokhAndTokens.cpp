#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, a, b;
    scanf("%lld%lld%lld", &n, &a, &b);

    for(int i = 0; i<n; i++){
        if(i != 0){
            cout << " ";
        }
        ll x;
        scanf("%lld", &x);
        if(a >= b){
            printf("%d", 0);
        } else {
            ll tokensExtra = ((x % b) * (a % b)) % b;
            ll ans = 0;
            ans += tokensExtra/a;

            printf("%lld", ans);
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll l, r;
    scanf("%lld%lld", &l, &r);

    cout<<"YES\n";

    for(ll i = l; i<=r; i++){
        printf("%lld %lld\n", i, i+1);
        i++;
    }
}
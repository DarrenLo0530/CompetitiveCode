#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t;
    scanf("%lld", &t);
    while(t--){
        ll s, d;
        scanf("%lld%lld", &s, &d);
        
    
        ll b = (s-d);
        if(b % 2 != 0){
            cout<<"impossible\n";
            continue;
        }
        
        b/=2;
        
        ll a = d + b;
        if(a < 0 || b < 0){
            cout<<"impossible\n";
        } else {
            printf("%lld %lld\n", a, b);
        }

    }
}
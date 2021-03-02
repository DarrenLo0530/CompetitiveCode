#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

pair<ll, ll> reduce(pair<ll, ll> f){
    ll g = __gcd(f.first, f.second);

    return {f.first/g, f.second/g};
}
pair<ll, ll> lcm(ll first, ll second){
    ll g = __gcd(first, second);
    return {first/g, second};
}
int main(){
    ll t, w, b;
    scanf("%lld%lld%lld", &t, &w, &b);
    pair<ll, ll> l = lcm(w, b);
    ll app = t/l.first/l.second;
    ll ans = (max(0LL, app-1)) * (min(w, b));
    if(app > 0){
        ans +=  min(min(w, b), t - (app * l.first*l.second) + 1);
    }
    ans += min(min(w, b)-1, t);


    pair<ll, ll> frac = reduce({ans, t});
    printf("%lld/%lld\n", frac.first, frac.second);
    
    
}
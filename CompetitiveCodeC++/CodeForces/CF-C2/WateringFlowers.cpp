#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;

ll sqr(ll x){
    return x * x;
}
ll dist(ll x1, ll y1, ll x2, ll y2){
    return sqr(x1-x2) + sqr(y1-y2);
}

vector<pll> d;

int main(){
    ll n, x1, y1, x2, y2;
    scanf("%lld%lld%lld%lld%lld", &n, &x1, &y1, &x2, &y2);

    for(int i = 0; i<n; i++){
        ll x, y;
        scanf("%lld%lld", &x, &y);
        ll r1 = dist(x1, y1, x, y);
        ll r2 = dist(x2, y2, x, y);
        d.push_back({r1, r2});
    }

    sort(d.begin(), d.end(), greater<pll>());

    d.push_back({0, 0});

    ll ans = INFLL;
    ll lMax = 0;
    for(int i = 0; i<=n; i++){
        ans = min(ans, lMax + d[i].first);
        lMax = max(lMax, d[i].second);
    }

    cout << ans << '\n';
}


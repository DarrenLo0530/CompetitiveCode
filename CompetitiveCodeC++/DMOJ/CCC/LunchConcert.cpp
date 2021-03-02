#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

struct person {
    ll p, w, d;
};

vector<person> people;

ll calculate(ll c) {
    ll ans = 0;
    for(person pp: people) {
        ans += max(abs(pp.p - c) - pp.d, (ll) 0) * pp.w;
    }

    return ans;
}

ll solve(ll l, ll r) {
    if(l >= r) {
        return min(calculate(r), calculate(l));
    }

    ll mid1 = (l+r)/2;
    ll mid2 = mid1+1;

    ll p1 = calculate(mid1);
    ll p2 = calculate(mid2);

    if(p1 == p2) { 
        return p1;
    } else if(p2 < p1) {
        return solve(mid2, r);
    } else {
        return solve(l, mid1);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i<n; i++) {
        ll p, w, d;
        cin >> p >> w >> d;
        people.push_back(person{p, w, d});
    }

    cout << solve(0LL, 1000000000LL) << "\n";

}
#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int main(){
    int n;
    scanf("%d", &n);

    ll ans = 0;
    ll mx = 0;
    for(int i = 0; i<n; i++){
        ll x;
        cin >> x;
        mx = max(x, mx);
        ans += x;
    }

    ans = (ll) ceil(ans/(double)(n-1));
    cout << max(mx, ans) << '\n';
}
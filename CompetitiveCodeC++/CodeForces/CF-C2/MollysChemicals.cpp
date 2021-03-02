#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;

const int MX = 100005;
ll a[MX];
ll po[100];
ll psa[MX];

vector<pll> p;
int main(){
    int n, k;
    scanf("%d%d", &n, &k);

    for(int i = 1; i<=n; i++){
        scanf("%lld", a + i);
        psa[i] = psa[i-1] + a[i];
        p.push_back({psa[i], i});
    }

    po[0] = 1;
    int cnt = 0;
    if(k == -1){
        cnt = 1;
        po[1] = -1;    
    } else if(k != 1){
        for(cnt = 1; ; cnt++){
            po[cnt] = po[cnt-1] * k;
            if(po[cnt] > 1e15){
                break;
            }
        }
    }

    sort(p.begin(), p.end());
    ll ans = 0;
    for(int i = 0; i<=cnt; i++){
        for(int j = 0; j<=n; j++){
            ll desired = po[i] + psa[j];
            ll numAvailable = upper_bound(p.begin(), p.end(), make_pair(desired, (ll) INF)) - lower_bound(p.begin(), p.end(), make_pair(desired, (ll) j));
            //printf("i: %d j: %d num_available: %lld\n", i, j, numAvailable);
            numAvailable = max(0LL, numAvailable);
            ans += numAvailable;
        }
    }
    printf("%lld\n", ans);
}
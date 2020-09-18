#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const ll m = 1e9 + 7;
int main(){
    ll a, b;
    scanf("%lld%lld", &a, &b);
    ll ans = 0;
    for(int i = 1; i<=a; i++){
        ans = (ans + ((b*(b-1)/ 2) % m * (i*b%m + 1) % m)) % m;
    }
    printf("%lld\n", ans);
}
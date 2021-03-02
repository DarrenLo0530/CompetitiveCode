#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;

ll nums[500011];
ll psa[500011];
ll rpsa[500011];
ll suf[500011];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        scanf("%lld", nums + i);
        psa[i] = psa[i-1] + nums[i];
    }
    ll sum = psa[n];

    if(sum % 3 != 0){
        printf("0\n");
        return 0;
    }

    for(int i = n; i>=1; i--){
        rpsa[i] = rpsa[i+1] + nums[i];
    }

    for(int i = n; i>=1; i--){
        suf[i] = suf[i+1];
        if(rpsa[i] == sum/3){
            suf[i]++;
        }
    }

    
    ll ans = 0;
    for(int i = 1; i<=n-2; i++){
        if(psa[i] == sum/3){
            ans += suf[i+2];
        }
    }
    printf("%lld\n", ans);
}
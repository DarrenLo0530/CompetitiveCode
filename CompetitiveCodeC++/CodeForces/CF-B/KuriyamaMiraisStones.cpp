#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll nums[100001];
ll sorted[100001];


int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        ll x;
        scanf("%lld", &x);

        nums[i] = x;
        sorted[i] = x;


    }
    sort(sorted + 1, sorted + n + 1);
    for(int i = 1; i<=n; i++){
        nums[i] += nums[i-1];
        sorted[i] += sorted[i-1];
    }

    int q;
    scanf("%d", &q);

    while(q--){
        int o, l, r;
        scanf("%d%d%d", &o, &l, &r);
        ll ans;
        if(o == 1){
            ans = nums[r] - nums[l-1];
        } else {
            ans = sorted[r] - sorted[l-1];
        }

        printf("%lld\n", ans);
    }
}
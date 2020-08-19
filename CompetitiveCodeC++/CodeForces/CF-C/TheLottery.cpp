#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lcm(ll a, ll b){
    return a * b/__gcd(a, b);
}

ll nums[16];

int main(){
    ll n , m;
    while(cin >> n >> m){
        ll ans = n;
        for(int i = 0; i<m; i++){
            cin >> nums[i];
        }
        for(int i = 1; i<(1 << m); i++){
            int count = 0;

            ll l = 1;
            for(int j = 0; j<m; j++){
                if((1 << j) & i){
                    count++;
                    l = lcm(l, nums[j]);
                }
            }

            if(count % 2 == 0){
                ans += n/l;
            } else {
                ans -= n/l;
            }
        }

        cout<<ans<<'\n';

    }
}
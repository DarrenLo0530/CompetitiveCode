#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int top, bot;
ll lcm(int a, int b){
    return a*b/__gcd(a, b);
}

int main(){
    while(true){
        int n, t;
        scanf("%d%d", &n, &t);  

        vector<ll> coins;

        if(n == 0 && t == 0){
            break;
        }

        
        for(int i =0; i<n; i++){
            ll x;
            scanf("%lld", &x);
            coins.push_back(x);
        }

        for(int i = 0; i<t; i++){
            pair<ll, ll> ans = {0, 0x3f3f3f3f};
            ll x;
            scanf("%lld", &x);
            for(int i = 0; i<n; i++){
                for(int j = i+1; j<n; j++){
                    for(int k = j+1; k<n; k++){
                        for(int l = k+1; l < n; l++){
                            int m = lcm(lcm(lcm(coins[i], coins[l]), coins[j]), coins[k]);
                            ans.first = max(ans.first, (x/m) * m);
                            ans.second = min(ans.second, ((ll) ceil((double) x/m)) * m);
                        }
                    }
                }
            }

            cout<<ans.first<<" "<<ans.second<<'\n';
        }


        
    }
}
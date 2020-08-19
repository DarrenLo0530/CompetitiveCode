#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n, k;
    scanf("%lld%lld", &n, &k);
    set<ll> nums;
    set<ll> erased;
    

    for(int i = 0; i<n; i++){
        ll x;
        scanf("%lld", &x);
        nums.insert(x);
    }
    if(k == 1){
        cout<<n<<'\n';
        return 0;
    }

    for(ll i: nums){
        if(!erased.count(i)){
            if(nums.count(k * i)){
                erased.insert(k * i);
            }
        }
    }

    cout<<nums.size() - erased.size()<<'\n';
}
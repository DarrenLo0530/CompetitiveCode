#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll m = 1e9 + 7;

int main(){
    ll x, y, n;
    scanf("%lld%lld%lld", &x, &y, &n);

    vector<ll> nums;
    nums.push_back(x);
    nums.push_back(y);
    nums.push_back(y - x);  
    for(int i = 0; i<3; i++){
        nums.push_back(-nums[i]);
    }

    
    ll ans = (nums[(n - 1) % 6] + m + m + m) % m;
    cout<<ans<<'\n';
    
}
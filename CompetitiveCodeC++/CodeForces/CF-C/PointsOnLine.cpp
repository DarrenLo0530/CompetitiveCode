#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    int n, d;
    scanf("%d%d", &n, &d);
    vector<int> nums;
    for(int i =0 ; i<n; i++){
        int x;
        scanf("%d", &x);
        nums.push_back(x);
    }

    ll ans = 0;
    for(int i = 0; i<n; i++){
        ll numCanChoose = upper_bound(nums.begin(), nums.end(), nums[i] + d) - nums.begin() - 1 - i;
        ans += numCanChoose * (numCanChoose-1)/2;
    }

    cout<<ans<<'\n';



}
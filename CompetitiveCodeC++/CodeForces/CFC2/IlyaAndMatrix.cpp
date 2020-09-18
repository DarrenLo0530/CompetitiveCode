#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    scanf("%d", &n);
    vector<ll> nums;
    for(int i = 0; i<n; i++){
        int a;
        scanf("%d", &a);
        nums.push_back(a);
    }

    sort(nums.begin(), nums.end(), greater<int>());
    /*
    int maxAppearance = 0;
    while(n/pow(4, maxAppearance) > 1){
        maxAppearance++;
    } 
    maxAppearance++;
    */

    ll ans = 0;
    ll cul = 0;
    /*
    int powCount = 0;
    int numLevel = pow(4, 0);

    for(int i = 0; i<n; i++){
        if(numLevel <= 0){
            powCount++;
            maxAppearance--;
            numLevel = pow(4, powCount) - pow(4, powCount-1);
        }

        ans += maxAppearance * nums[i];
        numLevel--;
    }
    */
    int bound = 1;
    for(int i = 0; i<n; i++){
        if(i == bound){
            ans += cul;
            bound *= 4;
        }
        cul += nums[i];
        ans += nums[i];
    }

    cout<<ans<<'\n';
}
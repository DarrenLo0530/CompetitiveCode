#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll nums[4];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i<4; i++){
        scanf("%lld", nums + i);
    }
    swap(nums[2], nums[3]);
    ll totalPoss = 0;
    for(ll mid = 1; mid<=n; mid++){
        ll rb = 0x3f3f3f3f3f3fLL, lb = 0LL;
        for(int i = 0; i<4; i++){
            int r = (i + 1) % 4;
            //ASsume that corner is max(1), then the sum of the other 3 corners can not be greater than this as this is the max possible sum for this corner
            rb = min(rb, nums[i] + nums[r] + mid + n);
            //Assume each corner is min(1), then the sum of the other 3 corners can not go lower than this number as this is the min possible sum for the corner
            lb = max(lb, nums[i] + nums[r] + mid + 1);
        }
        //Sometimes max possible sum for a corner is less than the min possible sum for another corner resulting in negative, so ignore this.
        totalPoss += rb - lb + 1 > 0 ? rb - lb + 1 : 0;
    }

    cout<<totalPoss<<'\n';
}
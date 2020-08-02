#include <bits/stdc++.h>
using namespace std;

int nums[100003];
int main(){
    int n, k;
    scanf("%d%d", &n, &k);

    for(int i = 0; i<n; i++){
        scanf("%d", nums + i);
    }
    for(int i = 0; i<n; i++){
        if(nums[i] < 0 && k > 0){
            k--;
            nums[i] *= -1;
        }
    }

    sort(nums, nums+n);
    k %= 2;
    
    int ans = 0;
    for(int i = 0; i<n; i++){
        ans+=nums[i];
    }

    ans -= 2 * (nums[0] * k);
    printf("%d\n", ans);
}
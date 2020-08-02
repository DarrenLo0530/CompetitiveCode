#include <bits/stdc++.h>
using namespace std;

int nums[101];
int dp[3][101];
int main(){
    memset(dp, 0x3f3f3f3f, sizeof(dp));

    int n;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        int x;
        scanf("%d", &x);
        nums[i] = x;
    }

    dp[0][0] = dp[0][1] = dp[0][2] = 0;

    for(int i = 1; i<=n; i++){

        dp[0][i] = 1 + min(min(dp[0][i-1], dp[1][i-1]), dp[2][i-1]);

        if(nums[i] == 1 || nums[i] == 3){
            dp[1][i] = min(dp[0][i-1], dp[2][i-1]);
        }
        
        if(nums[i] == 2 || nums[i] == 3){
            dp[2][i] = min(dp[0][i-1], dp[1][i-1]);
        }


    }

    printf("%d", min(min(dp[0][n], dp[1][n]), dp[2][n]));
}
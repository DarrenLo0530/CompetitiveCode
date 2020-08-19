#include <bits/stdc++.h>
using namespace std;

bool dp[10001][101];
int nums[10001];
int main(){
    int m;
    scanf("%d", &m);
    while(m--){
        memset(dp, 0, sizeof(dp));

        int n, k;
        scanf("%d%d", &n, &k);

        for(int i = 1; i<=n; i++){
            scanf("%d", nums + i);
            nums[i] = abs(nums[i]) % k;
        }
        dp[0][0] = 1;

        for(int i = 1; i<=n; i++){
            for(int j = 0; j<k; j++){
                dp[i][j] = dp[i-1][(j - nums[i] + k ) % k] || dp[i-1][(j + nums[i] + k ) % k];
            }
        }

        if(dp[n][0]){
            cout<<"Divisible"<<'\n';
        } else {
            cout<<"Not divisible"<<'\n';
        }

        
    }
}
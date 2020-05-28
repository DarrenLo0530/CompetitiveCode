#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mod 1000000007

char grid[1002][1002];
ll dp[1002][1002];

int main(){
    int H, W;
    dp[0][1] = 1;
    scanf("%d %d", &H, &W);

    for(int i = 1; i<=H; i++){
        for(int j = 1; j<=W; j++){
            scanf(" %c", &grid[i][j]);
        }
    }

    for(int i = 1; i<=W; i++){
        for(int j = 1; j <= H; j++){
            if(grid[j][i] != '#'){
                dp[j][i] = (dp[j-1][i] + dp[j][i-1]) % mod;
            }
        }
    }

    cout<<dp[H][W];
}
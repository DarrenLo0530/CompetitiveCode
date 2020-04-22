#include <bits/stdc++.h>
using namespace std;

int m, n;
bool wasVis[102][102];
char grid[102][102];
int coins[102][102];
int dp[102][102];

int getCoins(){
    for(int i = m, j = 1; i>=1; i--){
        if(grid[i][j] == '.'){
            wasVis[i][j] = true;
            dp[i][j] = dp[i+1][j] + coins[i][j];
        } else {
            break;
        }
    }

    for(int j = 2; j<=n; j++){
        for(int i = 1; i<=m; i++){//Going downwards
            int res1 = 0;
            int res2 = 0;

            if(wasVis[i][j-1] && grid[i][j] == '.'){
                wasVis[i][j] = true;
                res1 = res2 = dp[i][j-1] + coins[i][j];
                dp[i][j] = max(dp[i][j], res1);

                for(int k = i+1; k<=m; k++){
                    if(grid[k][j] == '.'){
                        wasVis[k][j] = true;
                        res1 += coins[k][j];
                        dp[k][j] = max(dp[k][j], res1);
                    } else {
                        break;
                    }
                }

                for(int k = i-1; k>=1; k--){
                    if(grid[k][j] == '.'){
                        res2 += coins[k][j];
                        wasVis[k][j] = true;
                        dp[k][j] = max(dp[k][j], res2);
                    } else {
                        break;
                    }
                }
            }
        }
    }

    return dp[m][n];
}

int main(){
    while(true){
        memset(grid, 0, sizeof(grid));
        memset(dp, 0, sizeof(dp));
        memset(coins, 0, sizeof(coins));
        memset(wasVis, false, sizeof(wasVis));

        scanf("%d %d", &m, &n);
        if(!m && !n){
            break;
        }

        char c;
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                scanf(" %c", &c);
                if(c >= '0' && c <= '9'){
                    grid[i][j] = '.';
                    coins[i][j] = c - '0';
                } else {
                    grid[i][j] = c;
                }
            }
        }

        printf("%d\n", getCoins());
    }
}
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

int dp[2][1001];    
int black[1003];
char grid[1001][1001];
int main(){
    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;
    dp[1][0] = 0;

    int n, m, x, y;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            scanf(" %c", &grid[i][j]);
        }
    }
    //Count num black in each column
    for(int j = 0; j<m; j++){
        for(int i = 0; i<n; i++){
            if(grid[i][j] == '#'){
                black[j+1]++;
            }
        }
    }

    for(int i = 1; i<=m; i++){
        black[i] += black[i-1];
    }

    //Every column you have option
    //Change between x and y to black starting from curr
    //Change between x and y to white starting from curr


    for(int i = 1; i<=m; i++){
        //black = 0, white = 1
        //Set x to y to black
        if(dp[1][i-1] != INF){
            for(int d = x-1; d<=y-1; d++){
                if(d+i > m){
                    break;
                }

                dp[0][d + i] = min(dp[0][d+i], dp[1][i-1] + (d+1)*n - black[d + i] + black[i-1]);
            }
        }
        //Change to white
        if(dp[0][i-1] != INF){
            for(int d = x-1; d<=y-1; d++){
                if(d+i > m){
                    break;
                }

                dp[1][d + i] = min(dp[1][d+i] , dp[0][i-1] + black[d + i] - black[i-1]);
            }
        }
    }
    /*
    for(int i = 0; i<2; i++){
        for(int j = 0; j<=m; j++){
            printf("%d ", dp[i][j]);
        }
        cout<<'\n';
    }
    */

    printf("%d", min(dp[0][m], dp[1][m]));

}
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

int N, M;

char a[1002];
char b[1002];
int dp[1002][1002];

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 1; i<=N; i++){
        scanf(" %c", &a[i]);
    }
    for(int i = 1; i<=M; i++){
        scanf(" %c", &b[i]);
    }

    for(int i = 1; i<=M; i++){
        int ans = INF;
        for(int j = i-1; j>=0 && j>=i-3; j--){
            ans = min(ans, dp[j][0]);
        }
        dp[i][0] = 1 + ans;
    }

    for(int i = 1; i<=N; i++){
        int ans = INF;
        for(int j = i-1; j>=0 && j>=i-3; j--){
            ans = min(ans, dp[0][j]);
        }
        dp[0][i] = 1 + ans;
    }

    for(int i = 1; i<=M; i++){
        for(int j = 1; j<=N; j++){
            if(a[j] == b[i]){
                dp[i][j] = dp[i-1][j-1];
                continue;
            }
            
            int ans = dp[i-1][j-1];
            for(int k = i-1; k >= 0 && k >= i-3; k--){
                ans = min(ans, dp[k][j]);
            }
            for(int k = j-1; k >= 0 && k >= j-3; k--){
                ans = min(ans, dp[i][k]);
            }
            dp[i][j] = 1 + ans;
        }
    }

    cout << dp[M][N];
}
#include <bits/stdc++.h>
using namespace std;

int dp[3][100001];

int main(){
    int N;
    scanf("%d", &N);

    for(int i = 1; i<=N; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        dp[0][i] = max(dp[1][i-1], dp[2][i-1]) + a;
        dp[1][i] = max(dp[0][i-1], dp[2][i-1]) + b;
        dp[2][i] = max(dp[1][i-1], dp[0][i-1]) + c;
    }

    cout<<  max(max(dp[0][N], dp[1][N]), dp[2][N]);
}
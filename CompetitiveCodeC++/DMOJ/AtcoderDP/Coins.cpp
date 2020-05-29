#include <bits/stdc++.h>
using namespace std;

double dp[3001][3001];
//Let dp[i][j] be probability of getting j heads after i coins flipped
//dp[i][j] = dp[i-1][j-1] * probability of heads
//dp[i][j-1] = dp[i-1][j-1] * probability of tails

int main(){
    int N;
    scanf("%d", &N);

    dp[0][0] = 1;


    for(int i = 1; i<=N; i++){
        double p;
        scanf("%lf", &p);

        for(int j = 0; j<3000; j++){
            if(j >= 1){
                dp[i][j] += dp[i-1][j-1] * p;
            }
            dp[i][j] += dp[i-1][j] * (1-p);
        }
    }

    double ans = 0;
    for(int i = (N/2) + 1; i <= N; i++){
        ans += dp[N][i];
    }

    printf("%.10f", ans);

}
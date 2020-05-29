#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

int heights[100001];
int dp[100001];

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i = 1; i<=N; i++){
        scanf("%d", &heights[i]);
    }

    memset(dp, INF, sizeof(dp));
    dp[1] = 0;

    for(int i = 1; i<=N; i++){
        for(int k = 1; k<=K; k++){
            if(i+k > N){
                continue;
            }
            dp[i+k] = min(abs(heights[i+k] - heights[i]) + dp[i], dp[i+k]);
        }
    }

    cout<<dp[N];
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int a[101];
int N, K;

ll dp[100001];
ll prefixSum[100002];

int main(){
    scanf("%d %d", &N, &K);

    for(int i = 1; i<=N; i++){
        int x;
        scanf("%d", &x);

        a[i] = x;
    }

    dp[0] = 1;

    for(int kid = 1; kid<=N; ++kid){
        prefixSum[0] = dp[0];
        for(int i = 1; i<=K; ++i){
            prefixSum[i] = (prefixSum[i-1] + dp[i]) % mod;
        }

        for(int i = 0; i<=K; ++i){
            int L = max(0, i-a[kid]);
            dp[i] = (prefixSum[i] - prefixSum[L-1]);
            if(dp[i] < 0){
                dp[i] += mod;
            }
        }
    }

    cout<<dp[K];
}
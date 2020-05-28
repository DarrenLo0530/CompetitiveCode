#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int a[101];
int N, K;

ll dp[101][100001];
ll prefixSum[100002];



int main(){
    scanf("%d %d", &N, &K);

    for(int i = 1; i<=N; i++){
        int x;
        scanf("%d", &x);

        a[i] = x;
    }

    dp[0][0] = 1;

    for(int kid = 1; kid<=N; kid++){
        fill(prefixSum, prefixSum + 100002, 0);

        for(int u = K; u>=0; u--){
            int L = u;
            int R = min(u + a[kid] + 1, K+1);
            prefixSum[L] += dp[kid-1][u];
            prefixSum[R] -= dp[kid-1][u];
            if(prefixSum[R] < 0){
                prefixSum[R] += mod;
            }
            prefixSum[L] %= mod;            
        }
        
        ll p = 0;
        for(int i = 0; i<=K; i++){
            p+=prefixSum[i];
            p%=mod;
            dp[kid][i] += p;
        }
    }

    cout<<dp[N][K];
}
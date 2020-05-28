#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[401][401];
ll slimes[401];
//Min cost incurred to combine slimes from l to r

int main(){
    int N;
    scanf("%d", &N);

    for(int i = 1; i<=N; i++){
        int x;
        scanf("%d", &x);
        slimes[i] = x;
        slimes[i] += slimes[i-1];
    }

    for(int gap = 1; gap<=N; gap++){
        for(int i = 1; i<=N; i++){
            if(gap + i > N){
                continue;
            }

            for(int m = 0; m<gap; m++){
                if(dp[i][i+gap] == 0 || dp[i][i+m] + dp[i+m+1][i+gap] + slimes[i+gap] - slimes[i-1] < dp[i][i+gap]){
                    dp[i][i+gap] = dp[i][i+m] + dp[i+m+1][i+gap] + slimes[i+gap] - slimes[i-1];
                }
            }
        }
    }

    cout<<dp[1][N];
}
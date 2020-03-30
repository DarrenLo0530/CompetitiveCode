#include <bits/stdc++.h>
using namespace std;

int p[201];
int dp[201][201];

int getPoints(int l, int r){
    if(dp[l][r] != -1){
        return dp[l][r];
    }

    int ans = 0;
    for(int i = l+1; i<=r-1; i++){
        ans = max(ans, p[i] + p[l] + p[r] + getPoints(l, i) + getPoints(i, r));
    }

    dp[l][r] = ans;
    return ans;
}

int main(){
    int N;

    while(true){
        scanf("%d", &N);
        if(N == 0){
            break;
        }
        memset(dp, -1, sizeof(dp));
        memset(p, 0, sizeof(p));

        for(int i = 0; i<N; i++){
            scanf("%d", &p[i]);
        }

        cout<<getPoints(0, N-1);
    }
}
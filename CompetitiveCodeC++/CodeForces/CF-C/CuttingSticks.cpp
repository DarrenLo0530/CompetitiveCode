#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int l, n;
int cuts[51];
int dp[1001][1001];

int solve(int l, int r){
    if(dp[l][r] != INF){
        return dp[l][r];
    }


    int ans = INF;
    for(int i = 0; i<n; i++){
        if(cuts[i] <= l || cuts[i] >= r){
            continue;
        }

        ans = min(ans, r - l + solve(l, cuts[i]) + solve(cuts[i], r));
    }
    //No cuts to be made, so no cost
    if(ans == INF){
        return 0;
    }

    return dp[l][r] = ans;
}
int main(){
    while(true){
        memset(dp, INF, sizeof(dp));
        scanf("%d", &l);
        if(l == 0){
            break;
        }
        scanf("%d", &n);

        for(int i = 0; i<n; i++){
            scanf("%d", cuts + i);
        }

        printf("The minimum cutting is %d.\n", solve(0, l));
    }
}
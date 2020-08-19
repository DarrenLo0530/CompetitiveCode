#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int nums[10001];
int dp[10001][21][21];
int n, k;

int solve(int l, int pStart, int pEnd){
    int r = n - pStart - l + pEnd + 1;

    if(pStart + pEnd > k){
        return INF;
    }

    if(l >= r){
        return dp[l][pStart][pEnd] = 0;
    }

    if(nums[l] == nums[r]){
        return dp[l][pStart][pEnd] = solve(l + 1, pStart, pEnd); 
    } else {
        return dp[l][pStart][pEnd] = 1 + min(solve(l+1, pStart, pEnd + 1), solve(l, pStart + 1, pEnd));
    }
}
int main(){
    int t;
    memset(dp, INF, sizeof(dp));
    scanf("%d", &t);

    for(int c = 1;c<=t; c++){
        scanf("%d%d", &n, &k);
        for(int i = 1; i<=n; i++){
            scanf("%d", nums + i);
        }
        /*
        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=n; j++){
                cout<<dp[i][j]<<" ";
            }

            cout<<"\n";
        }
        */
        printf("Case %d: ", c);
        int difficulty = solve(1, 0, 0);
        if(difficulty == 0){
            printf("Too easy");
        } else if(difficulty > k){
            printf("Too difficult");
        } else {
            printf("%d", difficulty);
        }

        cout<<'\n';
    }
    
}
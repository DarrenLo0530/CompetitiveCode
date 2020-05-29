#include <bits/stdc++.h>
using namespace std;
int riceBalls[401];
bool dp[401][401];

int getRange(int l, int r){
    return riceBalls[r] - riceBalls[l-1];
}

int main(){
    int N;
    int ans = 0;
    cin>>N;
    
    for(int i = 1; i<=N; i++){
        scanf("%d", &riceBalls[i]);
        riceBalls[i] += riceBalls[i-1];
    }

    for(int i = 1; i<=N; i++){
        dp[i][i] = true;
        ans = max(ans, getRange(i, i));
    }

    for(int dist = 1; dist <= N; dist++){
        for(int l = 1; l<=N; l++){
            int r = l + dist;

            if(r > N){
                continue;
            }

            for(int m = l; m<=r-1; m++){
                if(dp[l][m] && dp[m+1][r] && getRange(l, m) == getRange(m+1, r)){
                    dp[l][r] = true;
                }
            }

            int pl = l;
            int pr = r;
            while(pl < pr-1){
                if(getRange(l, pl) == getRange(pr, r)){
                    if(dp[l][pl] && dp[pr][r] && dp[pl + 1][pr - 1]){
                        dp[l][r] = true;
                        break;
                    }
                } if(getRange(pr, r) < getRange(l, pl)){
                    pr--;
                } else {
                    pl++;
                }
            }
        
            
            if(dp[l][r]){
                ans = max(ans, getRange(l, r));
            }
        }

    }

    cout<<ans;
}
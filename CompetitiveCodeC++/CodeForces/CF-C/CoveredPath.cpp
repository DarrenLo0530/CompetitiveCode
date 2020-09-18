#include <bits/stdc++.h>
using namespace std;
int dp[100][1200];
int main(){
    int v1, v2, t, d;
    cin >> v1 >> v2 >> t >> d;
    memset(dp, -1, sizeof(dp));
    t--;
    dp[0][v1] = v1;
    for(int i = 1; i<=t; i++){
        for(int j = 0; j<1200; j++){
            for(int k = -d; k<=d; k++){
                if(j - k < 0 || dp[i-1][j-k] == -1){
                    continue;
                }

                dp[i][j] = max(dp[i][j], dp[i-1][j-k] + j);
            }
        }
    }

    cout<<dp[t][v2]<<'\n';
    
}
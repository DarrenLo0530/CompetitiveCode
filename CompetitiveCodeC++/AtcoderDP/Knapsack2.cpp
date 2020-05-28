#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int dp[101][100001]; //minWeight using [i] items to get to [j] value

int main(){
    int N, W;
    scanf("%d %d", &N, &W);
    
    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;


    for(int i = 1; i<=N; i++){
        int w, v;
        scanf("%d %d", &w, &v);

        for(int j = 100000; j>=0; j--){
            dp[i][j] = dp[i-1][j];
            
            int oldVal = j - v;
            if(oldVal < 0){
                continue;
            }

            if(dp[i-1][oldVal] != INF && dp[i-1][oldVal] + w < dp[i][j] && dp[i-1][oldVal] + w <= W){
                dp[i][j] = dp[i-1][oldVal] + w;
            }
        }  
    }

    int ans = 0;
    for(int i = 100000; i>=0; i--){
        if(dp[N][i] != INF){
            ans = i;
            break;
        }
    }

    cout<<ans;

}
#include <bits/stdc++.h>
using namespace std;
char triangle[2002][2002];
int dp[2002][2002];
int main(){
    int N;
    cin>>N;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            cin>>triangle[i][j];
            if(triangle[i][j] == '#'){
                dp[i][j] += 1;
            }
        }
    }


    for(int i = N; i>=1; i--){
        for(int j = 1; j <= N; j++){
            if(dp[i][j] > 0){
                dp[i][j] += min(min(dp[i+1][j], dp[i+1][j+1]), dp[i+1][j-1]);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            ans+=dp[i][j];
        }
    }
    cout<<ans;
}
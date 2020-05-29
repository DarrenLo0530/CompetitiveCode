#include <bits/stdc++.h>
using namespace std;
struct part{
    int c, v;
};
int B;

vector<part> parts[6];
int dp[6][3002]; //dp[i][j] Value obtained at cost j after buying parts from 1 - i

    int main(){
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    int T, N, c, v, t;
    scanf("%d %d", &T, &N);
    for(int i = 0; i<N; i++){
        cin>>c>>v>>t;
        parts[t].push_back(part{c, v});
    }
    cin>>B;


    for(int i = 1; i<=T; i++){
        for(part p: parts[i]){
            for(int j = 0; j<=B; j++){
                if(dp[i-1][j] != -1 && j + p.c < 3002){
                    dp[i][j + p.c] = max(dp[i][j + p.c], dp[i-1][j] + p.v);
                }
            }
        }
    }

    int ans = -1;
    for(int i = 0; i<=B; i++){
        ans = max(ans, dp[T][i]);
    }

    cout<<ans<<'\n';
}
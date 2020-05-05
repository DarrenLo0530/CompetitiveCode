#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll dp[3001][3001];
ll nums[3001];

int main(){
    //On T's turn, max
    //On Jiro's turn, min;
    int N;
    cin>>N;

    bool tTurn = N % 2 != 0;

    for(int i = 0; i<N; i++){
        cin>>nums[i];
        dp[i][i] = nums[i];
        if(!tTurn){
            dp[i][i] *= -1;
        }
    }

    for(int dist = 1; dist<N; dist++){
        tTurn ^= true;

        for(int i = 0; i<N; i++){
            if(dist + i >= N){
                continue;
            }
            if(tTurn){
                dp[i][i+dist] = max(dp[i+1][i+dist] + nums[i], dp[i][i+dist-1] + nums[i+dist]);
            } else {
                dp[i][i+dist] = min(dp[i+1][i+dist] - nums[i], dp[i][i+dist-1] - nums[i+dist]);
            }
        }
    }

    cout<<dp[0][N-1];

}
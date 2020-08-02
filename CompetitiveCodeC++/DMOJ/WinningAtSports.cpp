#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m = 1e9+7;

ll dp[2001][2001]; //Stress-free
ll dp1[2001][2001]; //Stressful

int main(){
    int t;
    scanf("%d", &t);

    for(int x = 1; x<=t; x++){
        memset(dp, 0, sizeof(dp));
        memset(dp1, 0, sizeof(dp1));

        string score;
        cin >> score;

        int aScore = stoi(score.substr(0, score.find('-')));
        int bScore = stoi(score.substr(score.find('-') + 1));


        dp[0][0] = dp[1][0] = dp1[0][0] =  1;

        for(int i = 0; i<=aScore; i++){
            for(int j = 0; j<=bScore; j++){

                if(i-1 >= 0 && i-1 > j){
                    dp[i][j] += dp[i-1][j];
                    dp[i][j] %= m;
                }

                if(j-1 >= 0){
                    dp[i][j] += dp[i][j-1];
                    dp[i][j] %= m;
                }

                if(j - 1 >= 0 && j - 1 >= i){
                    dp1[i][j] += dp1[i][j-1];
                    dp1[i][j] %= m;
                }

                if(i - 1 >= 0){
                    dp1[i][j] += dp1[i-1][j];
                    dp1[i][j] %= m;
                }

            }
        }
        
        printf("Case #%d: %lld %lld\n", x, dp[aScore][bScore], dp1[bScore][bScore]);
    }
}
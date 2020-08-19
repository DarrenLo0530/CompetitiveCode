#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
int main(){
    string a, b;
    int turnCounter = 1;
    while(true){
        memset(dp, 0, sizeof(dp));
        getline(cin, a);
        if(a[0] == '#'){
            break;
        }
        getline(cin, b);

        for(int i = 1; i<=a.size(); i++){
            for(int j = 1; j<=b.size(); j++){
                if(a[i-1] == b[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        printf("Case #%d: you can visit at most %d cities.\n", turnCounter, dp[a.size()][b.size()]);
        turnCounter++;
    }
}
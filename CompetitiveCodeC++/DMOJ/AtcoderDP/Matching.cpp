#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 +7;
//Use bits to represent compatibilities
//dp state??

int c[21][21];
long long dp[1 << 21]; //Max ways to get to combination of women taken


int main(){
    int N;
    
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            scanf("%d", &c[i][j]);
        }
    }
    
    dp[0] = 1;
    
    for(int j = 0; j<(1<<N); j++){
        int numSet = __builtin_popcount(j);

        for(int s = 0; s<N; s++){
            if(c[numSet - 1][s] && (1 << s) & j){
                dp[j] += dp[j - (1 << s)];
                dp[j] %= mod;
            }
        }
    }

    cout<<dp[(1 << N) - 1];
}
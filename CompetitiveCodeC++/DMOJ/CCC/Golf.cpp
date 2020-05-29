#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;
int dp[5400];
vector<int> clubs;

int main(){
    int d, n, c;
    scanf("%d %d", &d, &n);
    for(int i = 0; i<n; i++){
        scanf("%d", &c);
        clubs.push_back(c);
    }

    memset(dp, INF, sizeof(dp));
    dp[0] = 0;

    for(int i = 0; i<=d-1; i++){
        if(dp[i] == INF){
            continue;
        }

        for(int j: clubs){
            dp[i+j] = min(dp[i+j], dp[i] + 1);
        }
    }

    if(dp[d] == INF){
        printf("Roberta acknowledges defeat.");
    } else {
        printf("Roberta wins in %d strokes.", dp[d]);
    }
}
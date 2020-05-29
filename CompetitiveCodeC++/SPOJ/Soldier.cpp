#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int dp[7][1020];

vector<pair<int, int>> items[7];

int main(){
    int N, T;   
    scanf("%d %d", &N, &T);

    for(int i = 0; i<1020; i++){
        dp[0][i] = INF;
    }

    for(int i = 0; i<N; i++){
        int t, q, p;
        scanf("%d%d%d", &t, &p, &q);
        if(t <= 6) items[t].push_back(make_pair(p, q));
    }

    for(int i = 1; i<=6; i++){
        for(int j = 1; j<=T; j++){
            dp[i][j] = dp[i][j-1];

            for(auto item: items[i]){
                int price = item.first;
                int quality = item.second;

                if(j - price < 0){
                    continue;
                }

                dp[i][j] = max(dp[i][j], min(dp[i-1][j - price], quality));
            }
        }
        
    }

    cout<<dp[6][T]<<'\n';
}
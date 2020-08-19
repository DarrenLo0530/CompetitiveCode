#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000000005LL; 

ll costs[100001];
string words[2][100001];
ll dp[2][100001];

int main(){
    int n;

    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        scanf("%lld", costs + i);
    }

    for(int i = 0; i<2; i++){
        for(int j = 0; j<100001; j++){
            dp[i][j] = INF;
        }
    }

    for(int i = 1; i<=n; i++){
        string s;
        cin >> s;
        words[0][i] = s;
        reverse(s.begin(), s.end());
        words[1][i] = s;
    }

    dp[0][0] = dp[1][0] = 0;

    for(int i = 1; i<=n; i++){
        for(int currWord = 0; currWord < 2; currWord++){
            for(int prevWord = 0; prevWord<2; prevWord++){
                if(words[currWord][i] >= words[prevWord][i-1]){
                    dp[currWord][i] = min(dp[currWord][i], dp[prevWord][i-1]);
                }
            }
        }

        if(dp[1][i] != INF){
            dp[1][i] += costs[i];
        }
    }

    ll ans = min(dp[1][n], dp[0][n]);
    if(ans == INF){
        cout<<-1<<'\n';
    } else {
        cout<<ans<<'\n';
    }
}
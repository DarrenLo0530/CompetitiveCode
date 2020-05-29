#include <bits/stdc++.h>
using namespace std;

int dp[100]; //Maxv alue with ith bit set

int main(){
    int N, a;
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>a;
        int m = 0;

        for(int i = 0; i <= (log2(a) + 1); i++){
            if((a & (1 << i)) > 0){
                m = max(dp[i] + 1, m);
            }
        }

        for(int i = 0; i <= (log2(a) + 1); i++){
            if((a & (1 << i)) > 0){
                dp[i] = max(m, dp[i]);
            }
        }
    }

    int ans = 0;
    for(int i: dp){
        ans = max(i, ans);
    }

    cout<<ans;
}

#include <bits/stdc++.h>
using namespace std;
int n;
string s, t;
long long dp[1002][1002];
long long a[1002];
long long b[1002];

int main(){
    cin >> n; 
    cin >> s;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    cin>>t;
    for(int i = 1; i<=n; i++){
        cin>>b[i];
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if((s[i-1] == 'W' && t[j-1] == 'L' && a[i] > b[j]) || (s[i-1] == 'L' && t[j-1] == 'W' && a[i] < b[j])){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i] + b[j]);
            }
        }
    }

    cout<<dp[n][n]<<'\n';
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 0x3f3f3f3f
string s;

ll dp[61][61];
ll solve(int l, int r){
    if(dp[l][r] != -1){
        return dp[l][r];
    }

    if(l == r){
        return dp[l][r] = 1;
    } else if(l > r){
        return 0;
    }

    ll ans = 0;

    for(int i = l; i<=r; i++){
        for(int k = i; k<=r; k++){
            if(s[i] == s[k]){
                ans += 1 + solve(i+1 , k-1);
            }
        }
    }

    dp[l][r] = ans;

    return ans;
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        memset(dp, -1, sizeof(dp));
        cin >> s;
        cout<<solve(0, s.size()-1)<<'\n';
    }
}
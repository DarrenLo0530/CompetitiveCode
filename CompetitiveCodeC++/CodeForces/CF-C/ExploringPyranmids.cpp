#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m = 1e9;
string s;
ll dp[301][301];

ll solve(int l, int r){
    if(dp[l][r] != -1){
        return dp[l][r];
    }

    if(l == r){
        return 1;
    } else if(l > r){
        return 0;
    }

    ll ans = 0;
    for(int i = l+1; i<=r; i++){
        if(s[i] == s[l]){
            //Split indices l - i onto a new path rooted at s[l]
            //New paths new root is s[l+1]
            //Multiply by ways you can split remaining paths which is i to r rooted at s[l] which is equal to s[i] since you assume s[i] is returning from the
            //split path you just created
            ans += ((solve(l + 1, i - 1) % m) * (solve(i, r) % m)) % m;
            ans %= m;
        }
    }

    dp[l][r] = ans;
    return ans;
}

int main(){
    while(cin >> s){
        memset(dp, -1, sizeof(dp));
        cout<<solve(0, s.size() - 1)<<"\n";
    }
}
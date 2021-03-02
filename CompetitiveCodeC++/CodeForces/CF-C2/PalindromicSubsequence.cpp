#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
string s;

pair<int, string> dp[1001][1001];

pair<int, string> msa(pair<int, string> &a1, pair<int, string> &a2){
    if(a1.second < a2.second){
        return a1;
    } else {
        return a2;
    }
}
pair<int, string> solve(int l, int r){
    if(l == r){
        return {0, string(1, s[l])};
    } else if(l > r){
        return {0, ""};
    }

    if(dp[l][r].first != -1){
        return dp[l][r];
    }

    if(s[l] == s[r]){
        pair<int, string> a = solve(l+1, r-1);
        a.second = s[l] + a.second + s[l];
        return a;
    } else {
        pair<int, string> a1 = solve(l+1, r);
        pair<int, string> a2 = solve(l, r-1);
        a1.first++;
        a2.first++;

        if(a1.first < a2.first){
            return dp[l][r] = a1;
        } else if(a1.first > a2.first){
            return dp[l][r] = a2;
        } else {
            return dp[l][r] = msa(a1, a2);
        }
    }
}

int main(){
    while(cin >> s){
        for(int i = 0; i<=1000; i++){
            for(int j = 0; j<=1000; j++){
                dp[i][j] = {-1, ""};
            }
        }
        cout << solve(0, s.size()-1).second << '\n';
    }
}
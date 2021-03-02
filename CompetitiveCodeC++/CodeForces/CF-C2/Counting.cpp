#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
string dp[1010];
string add(string x, string y){
    string ans = "";
    int carry = 0;
    for(int i = 0; i<max(x.size(), y.size()); i++){
        int first = i >= x.size() ? 0 : x[i] - '0';
        int second = i >= y.size() ? 0 : y[i] - '0';
        ans += '0' + ((first + second + carry) % 10);
        carry = (first + second + carry)/10;
    }
    if(carry != 0){
        ans += '0' + carry;
    }

    return ans;
}
int main(){
    int n;
    for(int i = 0; i<1010; i++){
        dp[i] = "0";
    }
    dp[0] = "1";

    for(int i = 0; i<=1000; i++){
        dp[i+1] = add(add(dp[i+1], dp[i]), dp[i]);
        dp[i+2] = add(dp[i+2], dp[i]);
        dp[i+3] = add(dp[i+3], dp[i]);
    }
    
    for(int i= 0; i<=1000; i++){
        reverse(dp[i].begin(), dp[i].end());
        int idx = 0;
        while(dp[i][idx] == '0'){
            idx++;
        }
        dp[i] = dp[i].substr(idx);
    }

    while(cin >> n){
        cout << dp[n] << '\n';
    }
}
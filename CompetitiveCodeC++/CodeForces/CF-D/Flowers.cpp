#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int MX = 1e5 + 1;
const int m = 1e9 + 7;
int dp[MX];
int psa[MX];

int main(){
    int t, k;
    dp[0] = 1;
    scanf("%d%d", &t, &k);

    for(int i = 0; i<MX; i++){
        dp[i + 1] = (dp[i+1] + dp[i]) % m;
        if(i + k < MX){
            dp[i + k] = (dp[i+k] + dp[i]) % m;
        }
    }
    for(int i = 1; i < MX; i++){
        psa[i] = (psa[i-1] + dp[i]) % m;
    }
    for(int i = 0; i<t; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        int ans = (psa[b] - psa[a-1] + m) % m;
        cout << ans << "\n";
        
    }

}
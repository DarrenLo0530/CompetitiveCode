#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int m = 1e9 + 7;
int dp[1000];

int solve(int n, int k){
    if(n < 0){
        return 0;
    } else if(n == 0){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = 0;
    for(int i = 1; i<=k; i++){
        dp[n] = (dp[n] + solve(n-i, k)) % m;
    }

    return dp[n];
}

int main(){
    memset(dp, -1, sizeof(dp));

    int n, k, d;
    scanf("%d%d%d", &n, &k, &d);
    int ans = solve(n, k);

    //Number of solutions WITHOUT a number atleast d
    memset(dp, -1, sizeof(dp));
    ans = (ans - solve(n, d-1) + m) % m;

    printf("%d\n", ans);
}
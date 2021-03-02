#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int m = 1e8;
int dp[101][101][2];
int n1, n2, k1, k2;

int solve(int f, int h, int c){
    if(f < 0 || h < 0){
        return 0;
    }

    if(!f && !h){
        return 1;
    }

    if(dp[f][h][c] != -1){
        return dp[f][h][c];
    }

    dp[f][h][c] = 0;
    if(c == 0){
        for(int i = 1; i<=k1 && i<=f; i++){
            dp[f][h][c] = (dp[f][h][c] + solve(f-i, h, 1)) % m;
        }
    } else {
        
        for(int i = 1; i<=k2 && i<=h; i++){
            
            dp[f][h][c] = (dp[f][h][c] + solve(f, h-i, 0)) % m;
        }
    }

    return dp[f][h][c];
}

int main(){
    scanf("%d%d%d%d", &n1, &n2, &k1, &k2);

    memset(dp, -1, sizeof(dp));
    int ans = solve(n1, n2, 0);
    memset(dp, -1, sizeof(dp));
    ans = (ans + solve(n1, n2, 1)) % m;



    printf("%d\n", ans);
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[100002];
int h[100002];
ll dp[3][100002];

int main(){
    int n;

    memset(dp, -1, sizeof(dp));
    dp[0][0] = dp[1][0] = 0;

    scanf("%d", &n);

    x[0] = -0x3f3f3f3f;
    x[n+1] = 2*0x3f3f3f3f;

    for(int i = 1; i<=n; i++){
        scanf("%d%d", x+i, h+i);
    }

    for(int i = 1; i<=n; i++){
        //Don't cut curr tree
        dp[2][i] = max(max(dp[2][i-1], dp[1][i-1]), dp[0][i-1]);

        //Cut curr tree left
        if(x[i] - h[i] > x[i-1]){
            //Prev tree cut left or not cut
            dp[0][i] = max(max(dp[0][i], dp[0][i-1] + 1), dp[2][i-1] + 1);
        }

        if(x[i-1] + h[i-1] < x[i] - h[i]){
            dp[0][i] = max(dp[0][i], dp[1][i-1] + 1);
        }

        //Cut curr tree to right
        if(x[i] + h[i] < x[i+1]){
            //Prev tree was cut left, right or uncut(doesnt matter)
            dp[1][i] = max(max(dp[0][i-1], dp[1][i-1]), dp[2][i-1]) + 1;
        }
    }
/*
    for(int i = 0; i<3; i++){
        for(int j = 0; j<=n; j++){
            cout << dp[i][j] << " ";
        }
        cout<<"\n";
    }
*/

    printf("%lld", max(dp[2][n], max(dp[1][n], dp[0][n])));
}
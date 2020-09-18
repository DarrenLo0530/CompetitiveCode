#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 100000000000000LL

ll c[101], p[101][101], dp[101][101][101];
//dp[i][j][k] i = numTree, j = numContiguous, k = numColourUsed
int main(){
    memset(dp, -1, sizeof(dp));
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i<=n; i++){
        scanf("%lld", c + i);
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            scanf("%lld", &p[i][j]);
        }
    }

    for(int i = 0; i<101; i++){
        for(int j = 0; j<101; j++){
            for(int k =0; k<101; k++){
                dp[i][j][k] = INF;
            }
        }
    }

    for(int i = 1; i<=m; i++){
        dp[0][i][0] = 0;

    }

    //if j == colourNum
    //dp[treeNum][j][contNum] + p[treeNum][colourNum] = dp[treeNum + 1][colourNum][contNum]
    //else
    //dp[treeNum][j][contNum] + p[treeNum][colourNum] = dp[treeNum+1][colourNum][contNum + 1]
    for(int treeNum = 1; treeNum <= n; treeNum++){
        if(c[treeNum] != 0){
            //Assume we coloured previous tree colour
            for(int colour = 1; colour<=m; colour++){
                //Assume we have this many contiguous subsegments already
                for(int contiguous = 1; contiguous <= k; contiguous++){
                    //Same colour, contiguous
                    if(colour != c[treeNum] || treeNum == 1){
                        dp[treeNum][c[treeNum]][contiguous] = min(dp[treeNum][c[treeNum]][contiguous], dp[treeNum-1][colour][contiguous-1]);
                    } else if(colour == c[treeNum]){
                        dp[treeNum][c[treeNum]][contiguous] = min(dp[treeNum][c[treeNum]][contiguous], dp[treeNum-1][colour][contiguous]);
                    }
                }
            }
        } else {
            for(int colourCurr = 1; colourCurr<=m; colourCurr++){
                for(int colourPrev = 1; colourPrev<=m; colourPrev++){
                    for(int cont = 1; cont<=k; cont++){
                        if(colourCurr != colourPrev || treeNum == 1){
                            dp[treeNum][colourCurr][cont] = min(dp[treeNum][colourCurr][cont], dp[treeNum-1][colourPrev][cont-1] + p[treeNum][colourCurr]);
                        } else {
                            dp[treeNum][colourCurr][cont] = min(dp[treeNum][colourCurr][cont], dp[treeNum-1][colourPrev][cont] + p[treeNum][colourCurr]);
                        }
                    }
                }
            }
        }
    }
    ll ans = INF;
    for(int i = 1; i<=m; i++){
        ans = min(ans, dp[n][i][k]);
    }
    if(ans >= INF){
        ans = -1;
    }
    
    cout<<ans<<'\n';
}
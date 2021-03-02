#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int dp[31][31];

int main(){
    int n;
    int cnt = 0;
    while(cin >> n){
        int last = 0;
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i<n; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            last = max(last, max(a, b));
            dp[a][b] = 1;
        }


        for(int mid = 0; mid<=last; mid++){
            for(int first = 0; first<=last; first++){
                for(int second = 0; second<=last; second++){
                    dp[first][second] += dp[first][mid] * dp[mid][second];
                }
            }
        }

        printf("matrix for city %d\n", cnt++);
        for(int i = 0; i<=last; i++){
            if(dp[i][i]){
                for(int j = 0; j<=last; j++){
                    for(int k = 0; k<=last; k++){
                        if(dp[j][i] * dp[i][k]){
                            dp[j][k] = -1;
                        }
                    }
                }
            }
        }

        for(int i = 0; i<=last; i++){
            for(int j = 0; j<=last; j++){
                if(j != 0){
                    printf(" ");
                }
                printf("%d", dp[i][j]);
            }
            printf("\n");
        }




    }
    
}
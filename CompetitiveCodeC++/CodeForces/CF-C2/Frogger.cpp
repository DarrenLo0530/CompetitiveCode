#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int x[201], y[201];
double d[201][201];
double dp[201];

int main(){
    int n;
    int cnt = 1;
    while(cin >> n){
        if(n == 0){
            break;
        }
        
        for(int i = 0; i<n; i++){
            scanf("%d%d", x + i, y + i);
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                d[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
            }
        }


        for(int i = 0; i<n; i++){
            dp[i] = INF;
        }

        dp[0] = 0;

        for(int i = 0; i<n; i++){
            for(int first = 0; first < n; first++){
                for(int second = 0; second < n; second++){
                    if(first == second){
                        continue;
                    }
                    
                    dp[second] = min(dp[second], max(dp[first], d[first][second]));
                }
            }
        }

        printf("Scenario #%d\n", cnt++);
        printf("Frog Distance = %.3f\n\n", dp[1]);
    }
}
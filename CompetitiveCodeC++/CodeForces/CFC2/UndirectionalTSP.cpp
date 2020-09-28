#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int grid[101][201];
int dp[101][201];
vector<int> dpPath[101][201];

bool smaller(vector<int> &v1, vector<int> &v2){
    for(int i = 0; i<min(v1.size(), v2.size()); i++){
        if(v1[i] < v2[i]){
            return true;
        } else if(v2[i] < v1[i]){
            return false;
        }
    }
    return v1.size() < v2.size();
}

int main(){
    int n, m;
    while(cin >> n >> m){   
        memset(grid, 0, sizeof(grid));
        memset(dp, INF, sizeof(dp));
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                dpPath[i][j].clear();
                scanf("%d", &grid[i][j]);
            }
        }

        //n is num rows
        //m is num cols
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i == 0){
                    dp[j][i] = grid[j][i];
                } else {
                    for(int c = -1; c<=1; c++){
                        if(grid[j][i] + dp[(j+c+n)%n][i-1] < dp[j][i]){
                            dpPath[j][i] = dpPath[(j+c+n)%n][i-1];
                            dpPath[j][i].push_back((j+c+n)%n);
                            dp[j][i] = grid[j][i] + dp[(j+c+n)%n][i-1];
                        } else if(grid[j][i] + dp[(j+c+n)%n][i-1] == dp[j][i]){
                            vector<int> newPath = dpPath[(j+c+n)%n][i-1];
                            newPath.push_back((j+c+n)%n);
                            if(smaller(newPath, dpPath[j][i])){
                                dpPath[j][i] = newPath;
                            }  
                        }
                    }
                }

                if(i == m-1){
                    for(int j=0; j<n; j++){
                        dpPath[j][i].push_back(j);
                    }
                }
            }
        }

        int ans = INF;
        int bestIdx = 0;
        for(int i = 0; i<n; i++){
            ans = min(ans, dp[i][m-1]);
        }

        vector<int> path;
        for(int i = 0; i<n; i++){
            if(dp[i][m-1] == ans){
                if(path.size() == 0 || smaller(dpPath[i][m-1], path)){
                    path = dpPath[i][m-1];
                }
            }
        }


        for(int i = 0; i<m; i++){
            if(i != 0){
                printf(" ");
            }
            printf("%d", path[i] + 1);
        }   
        printf("\n");
        printf("%d\n", ans);
    }
}
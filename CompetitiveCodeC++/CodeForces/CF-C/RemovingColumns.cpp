#include <bits/stdc++.h>
using namespace std;

bool cols[101];
char grid[101][101];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 0;i<n; i++){
        for(int j = 0; j<m; j++){
            scanf(" %c", &grid[i][j]);
        }
    }

    for(int t = 0; t<m; t++){
        for(int i = 0; i<n-1; i++){
            for(int j = 0; j<m; j++){
                if(cols[j] || grid[i][j] == grid[i+1][j]){
                    continue;
                }
                if(grid[i][j] < grid[i+1][j]){
                    break;
                } else {
                    cols[j] = true;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i<101; i++){
        ans += cols[i];
    }

    printf("%d\n", ans);
}
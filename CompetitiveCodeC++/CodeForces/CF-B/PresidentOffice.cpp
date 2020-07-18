#include <bits/stdc++.h>
using namespace std;

char grid[102][102];
int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
set<char> used;
int main(){
    int n, m;
    char c;
    scanf("%d%d %c", &n, &m, &c);
    memset(grid, '.', sizeof(grid));

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            scanf(" %c", &grid[i][j]);
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){

            if(grid[i][j] == c){
                for(auto d: directions){
                    int newX = j + d[0];
                    int newY = i + d[1];
                    used.insert(grid[newY][newX]);
                }   
            }
        }
    }

    int ans = used.size();
    if(used.count(c)){
        ans--;
    }
    if(used.count('.')){
        ans--;
    }
    printf("%d\n", ans);
}
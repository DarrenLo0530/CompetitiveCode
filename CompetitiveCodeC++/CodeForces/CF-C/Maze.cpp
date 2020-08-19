#include <bits/stdc++.h>
using namespace std;
char grid[501][501];
bool visited[501][501];

int n, m, k;

int movement[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool inRange(int x, int y){
    return y >= 0 && y < n && x >=0 && x < m;
}
void dfs(int x, int y){
    visited[y][x] = true;
    for(int i = 0; i<4; i++){
        int newX = x + movement[i][0];
        int newY = y + movement[i][1];
        if(inRange(newX, newY) && grid[newY][newX] == '.' && !visited[newY][newX]){
            dfs(newX, newY);
        }
    }

    if(k-- > 0){
        grid[y][x] = 'X';
    }
}

void solve(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == '.'){
                dfs(j, i);
                return;
            }
        }
    }
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            scanf(" %c", &grid[i][j]);
        }
    }

    solve();
    

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<grid[i][j];
        }

        cout<<"\n";
    }


}
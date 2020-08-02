#include <bits/stdc++.h>
using namespace std;

char grid[51][51];
bool visited[51][51];
int n, m;

int movement[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool dfs(char colour, pair<int, int> prev, pair<int, int> curr){
    visited[curr.second][curr.first] = true;

    for(int i = 0; i<4; i++){
        int newX = curr.first + movement[i][0];
        int newY = curr.second + movement[i][1];
        if(newX >= 0 && newX < m && newY >= 0 && newY < n){
            pair<int, int> coord = {newX, newY};
            if(grid[newY][newX] == colour && visited[newY][newX] && coord != prev){
                return true;
            } else if(grid[newY][newX] == colour && !visited[newY][newX]){
                if(dfs(colour, curr, coord)){
                    return true;
                }
            }
        }
    }

    return false;

}
int main(){
    scanf("%d%d", &n, &m);

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            scanf(" %c", &grid[i][j]);
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(!visited[i][j] && dfs(grid[i][j], {-1, -1}, {j, i})){
                cout<<"Yes\n";
                return 0;
            }
        }
    }

    cout<<"No\n";
}
#include <bits/stdc++.h>
using namespace std;

bool visited[21][21];
char grid[21][21];
int movement[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m, x, y;
char land;

int bfs(int sx, int sy){
    visited[sx][sy] = true;
    queue<pair<int, int>> toVisit;
    toVisit.push({sx, sy});

    int size = 0;

    bool isIn = false;

    while(!toVisit.empty()){
        auto curr = toVisit.front();
        toVisit.pop();
        size++;

        if(curr == make_pair(x, y)){
            isIn = true;
        }

        for(int i = 0; i<4; i++){
            int newX = curr.first + movement[i][0];
            int newY = curr.second + movement[i][1];
            newY = (newY + n) % n;
            if(newX < 0 || newX > m-1){
                continue;
            }
            if(!visited[newX][newY] && grid[newX][newY] == land){
                visited[newX][newY] = true;
                toVisit.push({newX, newY});
            }
        }
    }

    return isIn ? 0 : size;


}

int main(){
    while(cin >> m && cin >> n){
        memset(visited, false, sizeof(visited));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                scanf(" %c", &grid[i][j]);
            }
        }

        scanf("%d%d", &x, &y);
        land = grid[x][y];
        int ans = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(visited[i][j] || grid[i][j] != land){
                    continue;
                }            
                ans = max(ans, bfs(i, j));
            }
        }

        printf("%d\n", ans);

    }
}
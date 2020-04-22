#include <bits/stdc++.h>
using namespace std;
int n, m;
char grid[1001][1001];
bool vis[1001][1001];

struct pt{
    int x, y;
};

int movement[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char dir[4] = {'E', 'S', 'W', 'N'};

void traverseBackward(pt curr){
    int x = curr.x;
    int y = curr.y;
    vis[y][x] = true;

    for(int i = 0; i<4; i++){
        int prevX = x + movement[i][0];
        int prevY = y + movement[i][1];

        if(grid[prevY][prevX] == dir[(i+2)%4] && !vis[prevY][prevX]){
            traverseBackward(pt{prevX, prevY});
        }
    }
}

//Ans is number of separated
void traverse(pt curr){
    int x = curr.x;
    int y = curr.y;
    vis[y][x] = true;

    traverseBackward(curr);

    int cd = 0;
    for(int i = 0; i<4; i++){
        cd = (grid[y][x] == dir[i]) ? i: cd;
    }

    x += movement[cd][0];
    y += movement[cd][1];

    if(!vis[y][x] && grid[y][x] != 'F'){
        traverse(pt{x, y});
    }
}

int main(){
    memset(grid, 'F', sizeof(grid));
    scanf("%d %d", &n, &m);

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            scanf(" %c", &grid[i][j]);
        }
    }
    int ans = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(!vis[i][j]){
                ans++;
                traverse(pt{j, i});
            }
        }
    }

    cout<<ans;
}
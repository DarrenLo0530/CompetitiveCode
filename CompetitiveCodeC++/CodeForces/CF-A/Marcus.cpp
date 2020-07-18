#include <bits/stdc++.h>
using namespace std;

int m, n;
string check = "IEHOVA@#";
string ans = "";
bool visited[9][9];
char grid[9][9];
int movement[3][2] = {{0, -1}, {1, 0}, {-1, 0}};
string commands[3] = {"forth", "right", "left"};

bool traverse(int x, int y){
    visited[y][x] = true;

    if(grid[y][x] == '#'){
        return true;
    }

    if(check.find(grid[y][x]) == string::npos){
        return false;
    }

    for(int i = 0; i<3; i++){
        int nextX = x + movement[i][0];
        int nextY = y + movement[i][1];

        if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && !visited[nextY][nextX]){
            if(traverse(nextX, nextY)){
                if(grid[nextY][nextX] == '#'){
                    ans = commands[i] + "" + ans;
                } else {
                    ans = commands[i] + " " + ans;
                }
                return true;
            }
        }
    }

    return false;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &m, &n);
        ans = "";
        memset(visited, false, sizeof(visited));

        int startX, startY;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                scanf(" %c", &grid[i][j]);
                if(grid[i][j] == '@'){
                    startX = j, startY = i;
                }
            }
        }

        traverse(startX, startY);
        cout << ans << "\n";
    }
}
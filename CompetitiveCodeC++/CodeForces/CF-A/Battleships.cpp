#include <bits/stdc++.h>
using namespace std;

int n;
char grid[101][101];
string check = "@x";

int movement[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool removeShip(int x, int y){
    bool stillAlive = false;
    for(int i = 0; i<4; i++){
        int nextX = x;
        int nextY = y;

        do{
            if(grid[nextY][nextX] == 'x'){
                stillAlive = true;
            }

            grid[nextY][nextX] = '.';
            nextX -= movement[i][0];
            nextY -= movement[i][1];
        } while (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n && check.find(grid[nextY][nextX]) != string::npos);
    }

    return stillAlive;
}

int main(){
    int t;
    scanf("%d", &t);

    for(int c = 1; c<=t; c++){
        int numShips = 0;
        scanf("%d", &n);

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                scanf(" %c", &grid[i][j]);
            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(check.find(grid[i][j]) != string::npos){
                    if(removeShip(j, i)){
                        ++numShips;
                    }
                }
            }
        }

        printf("Case %d: %d\n", c, numShips);
    }
}
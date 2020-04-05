#include <bits/stdc++.h>
using namespace std;
#define mx 103
#define INF 0x3f3f3f3f

int N, M;
char grid[mx][mx];
bool vis[mx][mx];
int minDist[mx][mx];
int movement[4][2] = {{0, -1}, {1, 0}, {-1, 0}, {0, 1}};
char dir[4] = {'U', 'R', 'L', 'D'};

struct loc{
    int x, y;
};


void updateGrid(){
    for(int i = 0; i<mx; i++){
        for(int j = 0; j<mx; j++){
            if(grid[i][j] == 'C'){
                //Updating upwards
                for(int k = i; k>=0; k--){
                    if(grid[k][j] == 'W'){
                        break;
                    } else if(grid[k][j] == '.'){
                        grid[k][j] = 'W';
                    }
                }

                //Updating downwards
                for(int k = i; k<=mx; k++){
                    if(grid[k][j] == 'W'){
                        break;
                    } else if(grid[k][j] == '.'){
                        grid[k][j] = 'W';
                    }
                }

                //Updating to the left
                for(int k = j; k>=0; k--){
                    if(grid[i][k] == 'W'){
                        break;
                    } else if(grid[i][k] == '.'){
                        grid[i][k] = 'W';
                    }
                }

                //Updating to the right
                for(int k = j; k<=mx; k++){
                    if(grid[i][k] == 'W'){
                        break;
                    } else if(grid[i][k] == '.'){
                        grid[i][k] = 'W';
                    }
                }

                grid[i][j] = 'W';
            }
        }
    }
}


int main(){
    memset(grid, 'W', sizeof(grid));
    memset(minDist, INF, sizeof(minDist));

    scanf("%d %d", &N, &M);
    char c;
    loc start;

    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            scanf(" %c", &c);
            if(c == 'S'){
                start = loc{j, i};
                grid[i][j] = '.';
                minDist[i][j] = -1;
            } else if(c == '.'){
                minDist[i][j] = -1;
                grid[i][j] = c;
            } else {
                grid[i][j] = c;
            }
        }
    }

    updateGrid();
    //All Cameras and spaces they view changed to walls
    //Starting changed to open space

    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            cout<<grid[i][j];
        }
        cout<<"\n";
    }


    int steps = 0;
    queue<loc> tv;
    tv.push(start);
    vis[start.y][start.x] = true;
    
    while(!tv.empty()){
        queue<loc> nextTv;
        
        while(!tv.empty()){
            loc curr = tv.front();
            tv.pop();
            if(grid[curr.y][curr.x] == 'W'){
                continue;
            }

            if(grid[curr.y][curr.x] == '.'){
                if(minDist[curr.y][curr.x] != -1){
                    minDist[curr.y][curr.x] = min(minDist[curr.y][curr.x], steps);
                } else {
                    minDist[curr.y][curr.x] = steps;
                }
                for(int i = 0; i<4; i++){
                    int newX = curr.x + movement[i][0];
                    int newY = curr.y + movement[i][1];
                    if(grid[newY][newX] != 'W' && !vis[newY][newX]){
                        vis[newY][newX] = true;
                        nextTv.push(loc{newX, newY});
                    }
                }
            } else if(find(begin(dir), end(dir), grid[curr.y][curr.x]) != end(dir)){
                int newX = curr.x;
                int newY = curr.y;
                while(true){
                    vis[newY][newX] = true;
                    int currDir = 0;
                    for(int i = 0; i<4; i++){
                        if(grid[newY][newX] == dir[i]){
                            currDir = i;
                        }
                    }
                    newX += movement[currDir][0];
                    newY += movement[currDir][1];

                    if(grid[newY][newX] == '.' || grid[newY][newX] == 'W'){
                        break;
                    } else if(vis[newY][newX]){
                        break;
                    }
                }

                if(grid[newY][newX] == '.'){
                    vis[newY][newX] = true;
                    tv.push(loc{newX, newY});
                }
            }
        }

        steps++;
        tv = nextTv;        
    }

    for(int i = 0; i<mx; i++){
        for(int j = 0; j<mx; j++){
            if(minDist[i][j] != INF && !(i == start.y && j == start.x)){
                cout<<minDist[i][j]<<"\n";
            }
        }
    }
}
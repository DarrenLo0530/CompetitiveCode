#include <bits/stdc++.h>
using namespace std;
char grid[1001][1001];
int dist[1001][1001];
int dir[1001][1001];
int movement[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n, m;
        scanf("%d%d", &n, &m);
        pair<int, int> start;

        for(int i = 0; i<n; i++){
            scanf("%s", grid + i);
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 'S'){
                    start = {j, i};
                    
                }   
                dir[i][j] = 0;
                dist[i][j] = 0x3f3f3f3f;
            }
        }

        dist[start.second][start.first] = 0;
        dir[start.second][start.first] = 255;
        queue<pair<int, int>> toVisit;
        toVisit.push(start);

        int ans = -1;
        while(!toVisit.empty() && ans == -1){
            pair<int, int> coord = toVisit.front();
            toVisit.pop();
            for(int i = 0; i<8; i++){
                int multiplyCounter = 1;
                while(true){
                    int newX = coord.first + multiplyCounter * movement[i][0];
                    int newY = coord.second + multiplyCounter * movement[i][1];
                    if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newY][newX] != 'X' && !(dir[newY][newX] & (1 << i))){
                        if(grid[newY][newX] == 'F'){
                            ans = dist[coord.second][coord.first] + 1;
                            break;
                        }
                        
                        if(dir[newY][newX] == 0){
                            dist[newY][newX] = dist[coord.second][coord.first] + 1;
                            toVisit.push({newX, newY});
                        }
                        dir[newY][newX] |= (1 << i);
                    } else {
                        break;
                    }

                    multiplyCounter++;
                }
            }
        }
    


        printf("%d\n", ans);
    }

    
}
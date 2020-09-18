#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int, int> pii;
char grid[100][100];
int shortestPath[100][100];
int movement[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int w, h;


int cost(pii pos){
    char c = grid[pos.second][pos.first];
    if(c >= '0' && c <= '9'){
        return c - '0';
    }
    if(c == 'S' || c == 'D'){
        return 0;
    }

    return -1;
}
int djikstra(pii start, pii end){
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    memset(shortestPath, INF, sizeof(shortestPath));
    shortestPath[start.second][start.first] = 0;
    pq.push({0, start});
    while(!pq.empty() && pq.top().second != end){
        pii curr = pq.top().second;
        pq.pop();
        if(cost(curr) == -1){
            continue;
        }

        for(auto move: movement){
            int nextX = curr.first + move[0];
            int nextY = curr.second + move[1];
            if(nextY >= 0 && nextY < h && nextX >= 0 && nextX < w && shortestPath[nextY][nextX] > shortestPath[curr.second][curr.first] + cost(curr)){
                shortestPath[nextY][nextX] = shortestPath[curr.second][curr.first] + cost(curr);
                pq.push({shortestPath[nextY][nextX], {nextX, nextY}});
            }
        }    
    }

    return shortestPath[end.second][end.first];
}

int main(){
    while(cin >> w >> h){
        pii start, end;
        if(!w && !h){
            return 0;
        }
        
        for(int i = 0; i<h; i++){
            for(int j = 0; j<w; j++){
                scanf(" %c", &grid[i][j]);
                if(grid[i][j] == 'S'){
                    start = {j, i};
                } else if(grid[i][j] == 'D'){
                    end = {j, i};
                }
            }
        }

        printf("%d\n", djikstra(start, end));
    }
}

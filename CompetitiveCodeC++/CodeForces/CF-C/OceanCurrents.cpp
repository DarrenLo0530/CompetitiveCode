#include <bits/stdc++.h>
using namespace std;
int grid[1001][1001];
int cost[1001][1001];
int movement[8][2] = {{0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}};
bool visited[1001][1001];
int main(){
    int r, c;
    scanf("%d%d", &r, &c);
    for(int i = 1; i<=r; i++){
        for(int j = 1; j<=c; j++){
            scanf("%1d", &grid[i][j]);
        }
    }

    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        memset(cost, 0x3f3f3f3f, sizeof(cost));
        memset(visited, false, sizeof(visited));
        int rs, cs, re, ce;
        scanf("%d%d%d%d", &rs,&cs,&re,&ce);

        deque<pair<int, int>> toVisit;
        toVisit.push_back({cs, rs});
        cost[rs][cs] = 0;

        pair<int, int> end = {ce, re};

        while(!toVisit.empty()){
            pair<int, int> curr = toVisit.front();
            toVisit.pop_front();

            if(visited[curr.second][curr.first]){
                continue;
            }


            visited[curr.second][curr.first] = true;
            if(curr == end){
                printf("%d\n", cost[curr.second][curr.first]);
                break;
            }

            for(int i = 0; i<8; i++){
                pair<int, int> next = {curr.first + movement[i][0], curr.second + movement[i][1]};
                if(next.first >= 1 && next.first <= c && next.second >= 1 && next.second <= r){
                    if(!visited[next.second][next.first]){                        
                        if(grid[curr.second][curr.first] == i){
                            cost[next.second][next.first] = min(cost[next.second][next.first], cost[curr.second][curr.first]);
                            toVisit.push_front(next);
                        } else {
                            cost[next.second][next.first] = min(cost[next.second][next.first], cost[curr.second][curr.first] + 1);
                            toVisit.push_back(next);
                        }
                    }
                }
            }
        }

   
    }
}
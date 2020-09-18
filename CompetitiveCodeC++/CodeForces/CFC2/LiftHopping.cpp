#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int, int> pii;
int n, k;
typedef long long ll;

vector<pii> adj[102];
int t[10];
int cost[10][102];
int djikstra(int s, int e){
    memset(cost, INF, sizeof(cost));
    for(int i = 0; i<10; i++){
        cost[i][s] = 0;
    }

    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    pq.push({0, {s, 9}});

    while(!pq.empty()){
        int curr = pq.top().second.first;
        int elevator = pq.top().second.second;
        pq.pop();
        for(auto edge: adj[curr]){
            int elevatorEdge = edge.second;
            int dest = edge.first;
            if(elevatorEdge == elevator || elevator == 9){
                if(cost[elevatorEdge][dest] > cost[elevator][curr] + abs(dest - curr) * t[elevatorEdge]){
                    cost[elevatorEdge][dest] = cost[elevator][curr] + abs(dest - curr) * t[elevatorEdge];
                    pq.push({cost[elevatorEdge][dest], {dest, elevatorEdge}});
                }
            } else {
                if(cost[elevatorEdge][dest] > cost[elevator][curr] + abs(dest - curr) * t[elevatorEdge] + 60){
                    cost[elevatorEdge][dest] = cost[elevator][curr] + abs(dest - curr) * t[elevatorEdge] + 60;
                    pq.push({cost[elevatorEdge][dest], {dest, elevatorEdge}});
                }
            }
        }
    }

    int ans = INF;
    for(int i = 0; i<n; i++){
        ans = min(ans, cost[i][e]);
    }
    return ans;
}


int main(){
    while(cin >> n >> k){
        for(int i = 0; i<102; i++){
            adj[i].clear();
        }

        for(int i = 0; i<n; i++){
            scanf("%d", t + i);
        }

        cin.ignore(10000, '\n');
        for(int i = 0; i<n; i++){
            string s;
            getline(cin, s);
            stringstream sstream(s);
            int f;
            int prev = -1;
            while(sstream >> f){
                if(prev != -1){
                    adj[prev].push_back({f, i});
                    adj[f].push_back({prev, i});
                }
                prev = f;
            }
        }

        int ans = djikstra(0, k);
        if(ans == INF){
            printf("IMPOSSIBLE\n");
        } else {
            printf("%d\n", ans);
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int, int> pii;

vector<pair<int, int>> adj[20011];
int cost[200011];
int djikstra(int s, int t){
    memset(cost, INF, sizeof(cost));
    cost[s] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({cost[s], s});

    while(!pq.empty()){
        pair<int, int> curr = pq.top();
        if(curr.second == t){
            return cost[t];
        }
        pq.pop();

        for(auto edge: adj[curr.second]){
            int next = edge.first;
            int weight = edge.second;
            if(cost[next] > cost[curr.second] + weight){
                cost[next] = cost[curr.second] + weight;
                pq.push({cost[next], next});
            }
        }
    }

    return cost[t];
}

int main(){
    int t;
    scanf("%d", &t);
    for(int c = 1; c<=t; c++){
        int n, m, s, t;
        scanf("%d%d%d%d", &n, &m, &s, &t);
        for(int i = 0; i<20011; ++i){
            adj[i].clear();
            cost[i] = 0;
        }

        while(m--){
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }
        int ans = djikstra(s, t);
        printf("Case #%d: ", c);
        if(ans == INF){
            printf("unreachable\n");
        } else {
            printf("%d\n", ans);
        }
    }
}
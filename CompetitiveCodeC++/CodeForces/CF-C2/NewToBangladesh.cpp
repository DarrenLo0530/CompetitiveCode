#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

struct Road {
    //Node, timecost, distcost
    int n;
    ll t, d;
};

struct CustomCompare {
    //Minimize time then distance
    bool operator()(const Road &r1, const Road &r2){
        if(r1.t == r2.t){
            return r1.d > r2.d;
        }
        return r1.t > r2.t;
    }
};

vector<Road> adj[100001];
ll minDist[100001], minTime[100001];

void djikstra(int s, int e){
    for(int i = 0; i<100001; i++){
        minDist[i] = minTime[i] = INFLL;
    }

    minDist[s] = minTime[s] = 0LL;

    priority_queue<Road, vector<Road>, CustomCompare> pq;
    pq.push(Road{s, 0, 0});
    while(!pq.empty()){
        int currNode = pq.top().n;
        ll time = pq.top().t;
        ll dist = pq.top().d;
        pq.pop();

        if(currNode == e){
            break;
        }

        for(Road r: adj[currNode]){
            int newDist = dist + r.d;
            int newTime = time + r.t;
            if(newTime < minTime[r.n] || (newTime == minTime[r.n] && newDist < minDist[r.n])){
                minDist[r.n] = newDist;
                minTime[r.n] = newTime;
                pq.push(Road{r.n, minTime[r.n], minDist[r.n]});
            } 
        }
    }

    if(minDist[e] >= INFLL){
        printf("No Path.\n");
    } else {
        printf("Distance and time to reach destination is %lld & %lld.\n", minDist[e], minTime[e]);
    }
}
int main(){
    int t;
    scanf("%d", &t);
    for(int testCase = 0; testCase < t; testCase++){
        for(int i = 0; i<100001; i++){
            adj[i].clear();
        }
        
        int x, y;
        scanf("%d%d", &x, &y);
        for(int i = 0; i<y; i++){
            int a, b;
            ll c, d;
            scanf("%d%d%lld%lld", &a, &b, &c, &d);
            adj[a].push_back(Road{b, c, d});
            adj[b].push_back(Road{a, c, d});
        }
    
        int n;
        scanf("%d", &n);
        if(testCase != 0){
            printf("\n");
        }
        for(int i = 0; i<n; i++){
            int s, e;
            scanf("%d%d", &s, &e);
            djikstra(s, e);
        }

    }
}
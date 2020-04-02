#include <bits/stdc++.h>

using namespace std;
int K, N, M, A, B;
const int INF = 0x3f3f3f3f;
struct route{
    int d, t, h;
};
struct node{
    int d, w, c;
};

struct cmp{
    bool operator()(const node& n1, const node& n2){
        return n1.w > n2.w;
    }
};

priority_queue<node, vector<node>, cmp> pq;
vector<route> adj[2001];
int d[2001][201];


void getOpt(){
    d[A][0] = 0;
    pq.push(node{A, 0, 0});
    while(!pq.empty()){
        node curr = pq.top();
        pq.pop();

        for(route i: adj[curr.d]){
            int newCost = curr.c + i.h;
            int newDist = curr.w + i.t;
            if(newCost < K && newDist < d[i.d][newCost]){
                //cout<<i.d<<","<<newDist<<"\n";
                d[i.d][newCost] = newDist;
                pq.push(node{i.d, newDist, newCost});
            }
        }
    }
}

int main(){
    int a, b, t, h;
    memset(d, INF, sizeof(d));
    scanf("%d %d %d", &K, &N, &M);
    for(int i = 0; i<M; i++){
        scanf("%d %d %d %d", &a, &b, &t, &h);
        adj[a].push_back(route{b, t, h});
        adj[b].push_back(route{a, t, h});
    }
    scanf("%d %d", &A, &B);
    getOpt();

    int ans = INF;
    for(int i: d[B]){
        ans = min(ans, i);
    }

    if(ans == INF){
        cout<<-1;
    } else {
        cout<<ans;
    }
}
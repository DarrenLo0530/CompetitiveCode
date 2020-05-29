#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;

const int INF = 0x3f3f3f3f;
int N, T, K, D;
vector<pi> adj[5001];
int p[5001];
int d[5001];

struct cmp{
    bool operator()(pair<int, int> const& p1, pair<int, int> const& p2){
        return p1.second > p2.second;
    }
};

priority_queue<pi, vector<pi>, cmp> pq;

void upPaths(){
    pq.push(make_pair(D, 0));
    d[D] = 0;

    while(!pq.empty()){
        pi curr = pq.top();
        pq.pop();

        for(pi i: adj[curr.first]){
            if(i.second + curr.second < d[i.first]){
                d[i.first] = i.second + curr.second;
                pq.push(make_pair(i.first, i.second + curr.second));
            }            
        }
    }
}

int main(){
    int x, y, c;
    memset(p, INF, sizeof(p));
    memset(d, INF, sizeof(d));


    scanf("%d %d", &N, &T);

    for(int i = 0; i<T; i++){
        scanf("%d %d %d", &x, &y, &c);

        adj[x].push_back(make_pair(y, c));
        adj[y].push_back(make_pair(x, c));
    }

    scanf("%d", &K);
    for(int i = 0; i<K; i++){
        scanf("%d %d", &x, &y);
        p[x] = y;
    }

    scanf("%d", &D);
    upPaths();
    int ans = INF;
    for(int i = 1; i<= 5000; i++){
        ans = min(ans, p[i] + d[i]);
    }

    cout<<ans;
}

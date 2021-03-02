#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int MX = 1e3 + 5;
int v, e;

struct road {
    int x;
    double t;
};

struct cmp {
    bool operator() (const road &r1, const road &r2) {
        return r1.t < r2.t;
    }
};

vector<road> adj[MX];

double tim[MX];
int intersections[MX];

priority_queue<road, vector<road>, cmp> pq;


//Shortest path with least number of intersections

void solve() {
    for(int i = 0; i<MX; i++){
        tim[i] = INF;
    }
    memset(intersections, INF, sizeof(intersections));

    pq.push(road{1, 0});
    tim[1] = 0;
    intersections[1] = 0;

    while(!pq.empty()) {
        road curr = pq.top();
        pq.pop();

        if(curr.t > tim[curr.x]) {
            continue;
        }

        for(road v : adj[curr.x]) {
            if(v.t + curr.t <= tim[v.x]) {
                if(v.t + curr.t < tim[v.x]) {
                    tim[v.x] = v.t + curr.t;
                    pq.push(road{v.x, tim[v.x]});
                    intersections[v.x] = intersections[curr.x] + 1;
                } else {
                    intersections[v.x] = min(intersections[v.x], intersections[curr.x] + 1);
                }
            }

        }
    }

    printf("%d\n", intersections[v]);
    printf("%.0f\n", (tim[v]/0.75 - tim[v]));
}

int main(){
    scanf("%d%d", &v, &e);
    for(int i = 0; i<e; i++){
        int m, n, d, s;
        scanf("%d%d%d%d", &m, &n, &d, &s);
        double t = (d/(double)s) * 60;    
        adj[m].push_back(road{n, t});
        adj[n].push_back(road{m, t});
    }
    solve();

}

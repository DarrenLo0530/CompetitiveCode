#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int n, w, d;
const int MX = 200000 + 10;
set<int> walkways[MX];
int nextStop[MX];
int prevStop[MX];
int stationNumber[MX];
int number[MX];

struct node {
    int v, dist;
};

struct cmp {
    bool operator() (const node &n1, const node &n2) {
        return n1.dist > n2.dist;
    }
};


int solve() {
    vector<int> minDist(MX, INF);
    priority_queue<node, vector<node>, cmp> pq;

    pq.push(node{1, 0});
    minDist[1] = 0;
    while(!pq.empty()) {
        node curr = pq.top();
        pq.pop();

        if(curr.dist > minDist[curr.v]) {
            continue;
        }

        for(int i : walkways[curr.v]) {
            if(1 + minDist[curr.v] < minDist[i]) {
                minDist[i] = 1 + minDist[curr.v];
                pq.push(node{i, minDist[i]});
            }
        }

        if(nextStop[curr.v] != 0) {
            if((number[nextStop[curr.v]] - 1) < minDist[nextStop[curr.v]]) {
                minDist[nextStop[curr.v]] = (number[nextStop[curr.v]] - 1);
                pq.push(node{nextStop[curr.v], minDist[nextStop[curr.v]]});
            }
        }
    }


    //First stop   
    return minDist[n];
}

int main(){
    scanf("%d%d%d", &n, &w, &d);

    for(int i = 0; i<w; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        walkways[a].insert(b);
    }

    int prev = -1;
    for(int i = 1; i<=n; i++) {
        if(prev == -1) {
            scanf("%d", &prev);
            stationNumber[i] = prev;
            number[prev] = i;
        } else {
            int x;
            scanf("%d", &x);
            number[x] = i;
            stationNumber[i] = x;
            nextStop[prev] = x;
            prevStop[x] = prev;
            prev = x;
        }
    }

        
    for(int i = 0; i<d; i++) {
        int x, y;
        scanf("%d%d", &x, &y);

        //Can prolly clean this up with swap
        int a = stationNumber[x];
        int b = stationNumber[y];

        swap(prevStop[a], prevStop[b]);
        nextStop[prevStop[a]] = a;
        nextStop[prevStop[b]] = b;

        swap(nextStop[a], nextStop[b]);
        prevStop[nextStop[a]] = a;
        prevStop[nextStop[b]] = b;

        number[b] = x;
        number[a] = y;
        stationNumber[x] = b;
        stationNumber[y] = a;

        int ans = solve();

       printf("%d\n", ans);
    }



}
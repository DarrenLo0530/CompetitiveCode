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

//The order of stations stations[i] = station number of ith station
int stations[MX];
int walkDist[MX];
int minDist[MX];

int locations[MX];

int main(){
    scanf("%d%d%d", &n, &w, &d);

    for(int i = 0; i<w; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        walkways[b].insert(a);
    }

    for(int i = 1; i<=n; i++) {
        scanf("%d", &stations[i]);
        locations[stations[i]] = i;
    }

    queue<int> tv;
    memset(walkDist, INF, sizeof(walkDist));
    walkDist[n] = 0;
    tv.push(n);
    while(!tv.empty()) {
        int curr = tv.front();
        tv.pop();

        for(int i: walkways[curr]) {
            if(walkDist[i] == INF) {
                walkDist[i] = walkDist[curr] + 1;
                tv.push(i);
            }
        }
    }
    
    multiset<int> ans;
    for(int i = 1; i<=n; i++) {
        ans.insert(minDist[i] = locations[i] - 1 + walkDist[i]);
    }

    for(int i = 0; i<d; i++) {
        int x, y;
        scanf("%d%d", &x, &y);

        ans.erase(ans.find(minDist[stations[x]]));
        ans.erase(ans.find(minDist[stations[y]]));

        swap(stations[x], stations[y]);

        minDist[stations[x]] = x - 1 + walkDist[stations[x]];
        minDist[stations[y]] = y - 1 + walkDist[stations[y]];

        ans.insert(minDist[stations[x]]);
        ans.insert(minDist[stations[y]]);


        printf("%d\n", *ans.begin());
    }
}
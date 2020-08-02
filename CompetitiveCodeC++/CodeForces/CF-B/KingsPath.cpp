#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mx = 1e9;

int moves[8][2] = {{0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 0}, {-1, 0}};
set<pii> allowed;
set<pii> visited;
queue<pair<pii, ll>> toVisit;

int main(){
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    
    pii last = {x1, y1};

    int n;
    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        int r, a, b;
        scanf("%d%d%d", &r, &a, &b);
        for(int j = a; j<=b; j++){
            allowed.insert({r, j});
        }
    }
    pii start = {x0, y0};
    toVisit.push({start, 0});
    visited.insert(start);

    while(!toVisit.empty()){
        pii curr = toVisit.front().first;
        ll dist = toVisit.front().second;
        toVisit.pop();

        if(curr == last){
            printf("%lld\n", dist);
            return 0;
        }

        for(int i = 0; i<8; i++){
            int newX = curr.first + moves[i][0];
            int newY = curr.second + moves[i][1];
            pii next = {newX, newY};


            if(allowed.count(next) && !visited.count(next)){
                visited.insert(next);
                toVisit.push({next, dist + 1});
            }
        }
    }

    printf("-1\n");
}
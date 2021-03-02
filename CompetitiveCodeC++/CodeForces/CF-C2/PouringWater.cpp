#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;


pii getWater(ll x){
    return {x / 100000, x % 100000};
}

ll toWater(pii x){
    return (ll) x.first * 100000 + x.second;
}
int solve(int a, int b, int c){
    queue<ll> tv;  
    unordered_map<ll, int> vis;
    tv.push(0);
    vis[0] = 0;

    while(!tv.empty()){
        ll next = tv.front();
        tv.pop();
        pii w = getWater(next);
        pii poss[6];
        poss[0] = {0, w.second};
        poss[1] = {w.first, 0};
        poss[2] = {a, w.second};
        poss[3] = {w.first, b};
        poss[4] = {min(a, w.first + w.second), w.second - (min(a, w.first + w.second) - w.first)};
        poss[5] = {w.first - (min(b, w.first + w.second) - w.second), min(b, w.first + w.second)};

        for(int i = 0; i<6; i++){
            if(poss[i].first == c || poss[i].second == c){
                return vis[next]+1;
            }
            ll wat = toWater(poss[i]);
            if(vis.find(wat) == vis.end()){
                vis[wat] = vis[next] + 1;
                tv.push(wat);
            }

        }
    }   

    return -1;
}
int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int ans = solve(a, b, c);
        printf("%d\n", ans);
    }
    
}
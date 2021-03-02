#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
    ll x, y, z;
};

struct Cube {
    Point p1, p2;
};

ll calculateArea(Cube c1){
    return abs((c1.p1.x - c1.p2.x) * (c1.p1.y - c1.p2.y) * (c1.p1.z - c1.p2.z));
}

Cube intersectionCubes(Cube c1, Cube c2){
    if(c1.p1.x < 0){
        return c2;
    }

    ll x1 = max(c1.p1.x, c2.p1.x);
    ll y1 = max(c1.p1.y, c2.p1.y);
    ll z1 = max(c1.p1.z, c2.p1.z);

    ll x2 = min(c1.p2.x, c2.p2.x);
    ll y2 = min(c1.p2.y, c2.p2.y);
    ll z2 = min(c1.p2.z, c2.p2.z);

    if(x1 > x2 || y1 > y2 || z1 > z2){
        return Cube{Point{0, 0, 0}, Point{0, 0, 0}};
    }
    
    return Cube{Point{x1, y1, z1}, Point{x2, y2, z2}};
}

int main(){
    while(true){
        int n;
        scanf("%d", &n);
        if(n == 0){
            break;
        }
        
        ll ans = 0;
        vector<Cube> cubes;
        for(int i = 0; i<n; i++){
            ll x, y, z, d;
            scanf("%lld%lld%lld%lld", &x, &y, &z, &d);
            cubes.push_back(Cube{Point{x, y, z}, Point{x + d, y + d, z + d}});  
        }
        
        Cube intersection = Cube{Point{-1, -1, -1}, Point{-1, -1, -1}};
        for(int i = 0; i<n; i++){
            intersection = intersectionCubes(intersection, cubes[i]);
        }
        cout<<calculateArea(intersection)<<"\n";
    }

}
#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long double, long double> pdd;
struct Circle {
    long double h, k, r;
};

vector<Circle> circles;
bool possible[4];
void solve(){
    long double d = sqrt(pow(circles[0].h - circles[2].h, 2) + pow(circles[0].k - circles[2].k, 2));

    for(int i = 0; i<4; i++){
        Circle &c = circles[i];
        Circle &b1 = i <= 1 ? circles[2] : circles[0];
        Circle &b2 = i <= 1 ? circles[3] : circles[1];

        //Inside ring
        if(d + c.r <= b1.r){
            possible[i] = true;
        }
        //Outside of ring
        if(c.r + b2.r <= d){
            possible[i] = true;
        }
        //
        if(d + b2.r <= c.r){
            possible[i] = true;
        }
    }
}

int main(){
    for(int i =0; i<2; i++){
        ld x, y, r1, r2;
        cin >> x >> y >> r1 >> r2;
        circles.push_back(Circle{x, y, r1});
        circles.push_back(Circle{x, y, r2});
    }

    solve();
    int ans = 0;
    for(int i = 0; i<4; i++){
        ans += possible[i];
    }
    printf("%d\n", ans);


}
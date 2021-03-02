#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef long double ld;

const ld PI = acosl(-1.0);
const ld e = 1e-15;

ld solve(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3){
    ld angle = atan2l(y3 - y1, x3 - x1) - atan2l(y2 - y1, x2 - x1);
    while(angle < 0){
        angle += 2*PI;
    }
    while(angle >= 2*PI){
        angle -= 2*PI;
    }
    return min(angle, 2*PI - angle);
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        ld x1, y1, u1, v1, x2, y2, u2, v2;
        cin>>x1>>y1>>u1>>v1>>x2>>y2>>u2>>v2;

        ld angle1 = solve(x1, y1, u1, v1, x2, y2);
        ld angle2 = solve(x2, y2, u2, v2, x1, y1);
        
        if(fabs(angle1 - angle2) < e){
            printf("0\n");
        } else if(angle1 < angle2){
            printf("Hero\n");
        } else {
            printf("Heroine\n");
        }   
    }
}

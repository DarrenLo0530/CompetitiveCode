#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;


struct Point {
    int x, y;
};
Point pts[301];

int orientation(Point &p1, Point &p2, Point &p3){
    int ori = (p2.y - p1.y)*(p3.x - p2.x) - (p2.x - p1.x)*(p3.y - p2.y);
    if(!ori){
        return 0;
    }

    ori > 0 ? -1: 1;
    return ori;
}
double calculateArea(Point &p1, Point &p2, Point &p3){
    return fabs((p1.x*(p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / (double) 2);
}

int main(){

    int n;
    scanf("%d", &n);
    for(int i =0; i<n; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        pts[i] = Point{x, y};
    }

    double ans = 0;

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            double cwMax = 0;
            double ccwMax = 0;
            for(int k = 0; k<n; k++){
                if(k != i && k != j){
                    double area = calculateArea(pts[i], pts[j], pts[k]);
                    if(orientation(pts[i], pts[j], pts[k]) < 0){
                        cwMax = max(area, cwMax);
                    } else {
                        ccwMax = max(area, ccwMax);
                    }
                }
            }

            if(cwMax != 0 && ccwMax != 0){
                ans = max(ans, cwMax + ccwMax);
            }
        }
    }

    printf("%.9f\n", ans);

    
}
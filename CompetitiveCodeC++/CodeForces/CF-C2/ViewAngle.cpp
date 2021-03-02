#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

double distanceBetween(pii p1, pii p2){
    return pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2);
}

double radToDegree(double rad){
    return rad*180/PI;
}
double angleBetween(pii p1, pii p2){
    pii origin = {0, 0};
    double c = distanceBetween(p1, p2);
    double a = distanceBetween(p1, origin);
    double b = distanceBetween(p2, origin);

    if(p2.first < 0){
        return -radToDegree(acos((c-a-b)/(-2*sqrt(a)*sqrt(b))));
    }

    return radToDegree(acos((c-a-b)/(-2*sqrt(a)*sqrt(b))));
}

int main(){
    int n;
    scanf("%d", &n);
    pii base = {0, 1};
    vector<double> angles;
    for(int i = 0; i<n; i++){
        pii point;
        scanf("%d%d", &point.first, &point.second);
        angles.push_back(angleBetween(base, point));
    }

    sort(angles.begin(), angles.end());
    double ans = INF;
    for(int i = 0; i<angles.size(); i++){
        if(i != angles.size() - 1){
            ans = min(ans, 360 - (angles[(i+1) % n] - angles[i]));
        } else {
            ans = min(ans, angles[i] - (angles[(i+1) % n]));
        }
    }
    printf("%.10f\n", ans);

}
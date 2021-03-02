#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

struct Point {
    double x, y;
};

struct Circle {
    Point c;
    double r;
};


double dist(Point &a, Point &b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool containsPoint(Circle c, Point a){
    return dist(c.c, a) <= c.r;
}

Circle createCircle(Point a, Point b){
    double x = (a.x + b.x)/2.0;
    double y = (a.y + b.y)/2.0;
    Point center = Point{x, y};
    double radius = dist(center, a);
    return Circle{center, radius};
}

Circle createCircle(Point a, Point b, Point c){
    double bx = b.x - a.x;
    double by = b.y - a.y;
    double cx = c.x - a.x;
    double cy = c.y - a.y;

    double i = bx*bx + by*by;
    double j = cx*cx + cy*cy;
    double k = bx*cy - by*cx;

    Point center = {(cy*i - by*j)/(2*k), (bx*j - cx*i)/(2*k)};
    center.x += a.x;
    center.y += a.y;
    return Circle{center, dist(center, a)};
}

bool isValid(Circle c, vector<Point> &r){
    for(Point t: r){
        if(!containsPoint(c, t)){
            return false;
        }
    }
    return true;
}

Circle constructMinCircle(vector<Point> &r){
    if(r.size() == 0){
        return Circle{Point{0, 0}, 0};
    } else if(r.size() == 1){
        return Circle{r[0], 0};
    } else if(r.size() == 2){
        return createCircle(r[0], r[1]);
    }
    
    for(int i = 0; i<3; i++){
        for(int j = i+1; j<3; j++){
            Circle temp = createCircle(r[i], r[j]);
            if(isValid(temp, r)){
                return temp;
            }
        }
    }
    return createCircle(r[0], r[1], r[2]);
}

Circle welzlAlgo(vector<Point> &p, vector<Point> r, int n){
    if(n == 0 || r.size() == 3){
        return constructMinCircle(r);
    }

    int remIdx = rand() % n;
    Point rem = p[remIdx];
    swap(p[remIdx], p[n-1]);

    Circle excluding = welzlAlgo(p, r, n-1);

    if(containsPoint(excluding, rem)){
        return excluding;
    }

    r.push_back(rem);
    return welzlAlgo(p, r, n-1);
}


int main(){
    int c;
    scanf("%d", &c);
    while(c--){
        int n;
        scanf("%d", &n);
        vector<Point> p;
        for(int i = 0; i<n; i++){
            double x, y;
            scanf("%lf%lf", &x, &y);
            p.push_back(Point{x, y});
        }

        random_shuffle(p.begin(), p.end());
        vector<Point> r;
        Circle ans = welzlAlgo(p, r, p.size());
        printf("%.2f\n", ans.r);
        printf("%.2f %.2f\n", ans.c.x, ans.c.y);
    }
}
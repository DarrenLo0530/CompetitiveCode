#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

struct Point {
    double x, y;
};

struct Line{
    Point p1, p2;
};

struct StandardForm {
    int a, b, c;
};

StandardForm toStandardForm(Line l){
    int a = (l.p2.y - l.p1.y);
    int b = (l.p1.x - l.p2.x);
    int c = a*l.p1.x + b*l.p1.y;
    return StandardForm{a, b, c};
}

Point getIntersection(Line l1, Line l2){
    StandardForm sf1 = toStandardForm(l1), sf2 = toStandardForm(l2);
    int determinant = sf1.b*sf2.a - sf1.a*sf2.b;
    if(determinant == 0){
        return Point{INF, INF};
    }

    double x = (double)(sf2.c*sf1.b - sf1.c*sf2.b) / determinant;
    double y = (double)(sf1.c*sf2.a - sf1.a*sf2.c) / determinant;
    return Point{x, y};
}
bool isInLine(Line l, Point p){
    return p.x >= min(l.p1.x, l.p2.x) && p.x <= max(l.p1.x, l.p2.x) && p.y >= min(l.p1.y, l.p2.y) && p.y <= max(l.p1.y, l.p2.y);
}
bool isIntersect(Line l1, Line l2){
    Point intersection = getIntersection(l1, l2);
    if(intersection.x == INF){
        return false;
    }

    return isInLine(l1, intersection) && isInLine(l2, intersection);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int c = 0; c < t; c++){
        vector<Line> lines; 

        int n;
        scanf("%d", &n);
        vector<int> numIntersections(n, 0);
        for(int i = 0; i<n; i++){
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            lines.push_back(Line{Point{x1, y1}, Point{x2, y2}});
            for(int j = i-1; j>=0; j--){
                if(isIntersect(lines[i], lines[j])){
                    numIntersections[i]++;
                    numIntersections[j]++;
                }
            }
        }

        long long ans = 0;
        for(int i = 0; i<n; i++){
            ans += (long long) numIntersections[i]+1;
        }

        if(c != 0){
            printf("\n");
        }
        printf("%lld\n", ans);
    }
}
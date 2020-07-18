#include <bits/stdc++.h>
using namespace std;
struct Point{
    double x, y;
    bool operator==(const Point &p) {
        return x == p.x && y == p.y;
    }
};

int main(){
    while(true){
        vector<Point> points;
        for(int i = 0; i<4; i++){
            double x, y;
            if(!(cin >> x)){
                return 0;
            }
            cin >> y;
            points.push_back(Point{x, y});
        }

        Point duplicate;
        for(int i = 0; i<points.size(); i++){
            for(int j = i+1; j<points.size(); j++){
                if(points[i] == points[j]){
                    duplicate = points[i];
                    points.erase(points.begin() + j);
                    points.erase(points.begin() + i);
                    break;
                }
            }
        }


        double ansX = points[1].x + points[0].x - duplicate.x;
        double ansY = points[1].y + points[0].y - duplicate.y;
        printf("%.3f %.3f\n", ansX, ansY);
    }
}
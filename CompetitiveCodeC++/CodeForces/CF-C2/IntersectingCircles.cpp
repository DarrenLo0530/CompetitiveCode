#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> pdd;
const double e = 1e-4;

#define po(x) (x*x)

struct Point {
    double x, y;
    double dist(Point p){
        return sqrt(po(p.x - x) + po(p.y - y));
    }
    bool operator == (const Point &p) const {
        return p.x == x && p.y == y;
    }
    bool operator < (const Point &p) const {
        if(fabs(x - p.x) < e){
            return y < p.y;
        }
        return x < p.x;
    }
};

Point c1, c2, p1, p2;
double r1, r2;

vector<double> quad(double a, double b, double c){
    vector<double> ret;
    double det = po(b) - 4*a*c;
    if(det + e < 0){
        return ret;
    } else if(fabs(det) < e){
        ret.push_back(-b/(2*a));
    } else {
        ret.push_back((-b + sqrt(det))/(2*a));
        ret.push_back((-b - sqrt(det))/(2*a));
    }
    return ret;
}

int solve(){
    if(c1 == c2){
        if(r1 == r2 && r1 != 0){
            return -1;
        } 
        p1 = c1;
        return 1;
    }
    
    if(c1.dist(c2) == r1 + r2){
        if(r1 == 0){
            p1 = c1;
            return 1;
        } else if(r2 == 0){
            p1 = c2;
            return 1;
        }
    }

    if(r1 + r2 + e < c1.dist(c2)){
        return 0;
    }

    double a = 2*(c1.x-c2.x);
    double b = 2*(c1.y-c2.y);
    double c = -(c1.x * c1.x) - (c1.y * c1.y) + r1 * r1;
    c += c2.x * c2.x + c2.y * c2.y - (r2 * r2); 
    vector<Point> ans;
    //If circles are not stacked or side by side, either one works
    if(!fabs(b) < e){
        //Both circles are not side by side
        //If they are side by side, then the line we create will have a slope of INF
        //Then something will go wrong.
        //The else statement takes care of case where slope is INF by solving for y instead of x.
        //Then this INF slope will be 0 and all will be good
        double A = (po(a)/po(b)) + 1;
        double B = 2*((a * c / po(b)) + (c1.y * a / b) - c1.x);
        double C = po(c) / po(b) + (2 * c1.y* c / b) + po(c1.y) + po(c1.x) - po(r1);
        vector<double> ret = quad(A, B, C);
        if(ret.size() >= 1){
            p1 = {ret[0], (c + a * ret[0]) / (-b)};
        }
        if(ret.size() >= 2){
            p2 = {ret[1], (c + a * ret[1]) / (-b)};
        }
        return ret.size();
    } else {
        double A = (po(b)/po(a)) + 1;
        double B = 2*((b * c / po(a)) + (c1.x * b / a) - c1.y);
        double C = po(c) / po(a) + (2 * c1.x * c / a) + po(c1.x) + po(c1.y) - po(r1);
        vector<double> ret = quad(A, B, C);
        if(ret.size() >= 1){
            p1 = {(c + b * ret[0]) / (-a), ret[0]};
        }
        if(ret.size() >= 2){
            p2 = {(c + b * ret[1]) / (-a), ret[1]};
        }
        return ret.size();
    } 

}

int main(){
    while(scanf("%lf%lf%lf%lf%lf%lf", &c1.x, &c1.y, &r1, &c2.x, &c2.y, &r2) == 6){
        int ans = solve(); 
        if(ans == -1){
            printf("THE CIRCLES ARE THE SAME\n");
        } else if(ans == 0){
            printf("NO INTERSECTION\n");
        } else if(ans == 1){
            printf("(%.3lf,%.3lf)\n", p1.x + e, p1.y + e);
        } else if(ans == 2){
            if(p2 < p1){
                swap(p1, p2);
            }
            printf("(%.3lf,%.3lf)(%.3lf,%.3lf)\n", p1.x + e, p1.y + e, p2.x + e, p2.y + e);
        }
    }
}


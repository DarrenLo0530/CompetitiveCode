#include <bits/stdc++.h>

using namespace std;
typedef pair<double, double> pdd;
const double PI =  3.141592653589793;

pair<double, double> coords[3];
pdd slope (pdd c1, pdd c2){
    return make_pair(c2.second - c1.second, c2.first - c1.first);
}
pdd mid (pdd c1, pdd c2){
    return make_pair((c1.first + c2.first)/2,  (c1.second + c2.second)/2);
}

pdd intersection(pdd s1, pdd p1, pdd s2, pdd p2){
    double a1 = s1.first;
    double b1 = -s1.second;
    double c1 = p1.first * a1 + p1.second * b1;
    double a2 = s2.first;
    double b2 = -s2.second;
    double c2 = p2.first * a2 + p2.second * b2;


    double determinant = a1*b2-a2*b1;
    double x = (c1*b2-c2*b1)/determinant;
    double y = (c2*a1-a2*c1)/determinant;
    return {x, y};
}

void solve(){
    pdd s1 = slope(coords[0], coords[1]);
    pdd s2 = slope(coords[1], coords[2]);
    swap(s1.first, s1.second);
    swap(s2.first, s2.second);
    s1.first *= -1;
    s2.first *= -1;
    pdd m1 = mid(coords[0], coords[1]);
    pdd m2 = mid(coords[1], coords[2]);
    pdd circumCenter = intersection(s1, m1, s2, m2);
    double dist = sqrt(pow(coords[0].first - circumCenter.first, 2) + pow(coords[0].second - circumCenter.second, 2));
    double circumfrence = 2*PI*dist;
    printf("%.2f\n", circumfrence);
}

int main(){
    while(cin >> coords[0].first >> coords[0].second >> coords[1].first >> coords[1].second >> coords[2].first >> coords[2].second){
        solve();
    }
}
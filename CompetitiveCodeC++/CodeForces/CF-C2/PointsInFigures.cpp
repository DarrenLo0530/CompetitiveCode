#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> pdd;
vector<pair<int, pair<pdd, double>>> circles;
vector<pair<int, pair<pdd, pdd>>> rectangles;
int main(){
    int cnt = 0;
    while(++cnt){
        char shape;
        scanf(" %c", &shape);
        if(shape == '*'){
            break;
        } else if(shape == 'c'){
            double x, y, r;
            scanf("%lf%lf%lf", &x, &y, &r);
            circles.push_back({cnt, {{x, y}, r}});
        } else {
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            rectangles.push_back({cnt, {{x1, y1}, {x2, y2}}});
        }
    }

    double x, y;
    int pointCnt = 0;
    while(cin >> x >> y && ++pointCnt){
        if(x == 9999.9 && y == 9999.9){
            break;
        }
        vector<int> answers;
        for(int i = 0; i<circles.size(); i++){
            double cx = circles[i].second.first.first;
            double cy = circles[i].second.first.second;
            double cr = circles[i].second.second;
            if(sqrt(pow(cx - x, 2) + pow(cy - y, 2)) < cr){
                answers.push_back(circles[i].first);
            }
        }
        for(int i = 0; i<rectangles.size(); i++){
            double x1 = rectangles[i].second.first.first;
            double y1 = rectangles[i].second.first.second;
            double x2 = rectangles[i].second.second.first;
            double y2 = rectangles[i].second.second.second;
            if(x > x1 && x < x2 && y < y1 && y >y2){
                answers.push_back(rectangles[i].first);
            }
        }
        
        sort(answers.begin(), answers.end());
        if(answers.size() == 0){
            printf("Point %d is not contained in any figure\n", pointCnt);
        } else {
            for(int i: answers){
                printf("Point %d is contained in figure %d\n", pointCnt, i);
            }
        }
    }
}
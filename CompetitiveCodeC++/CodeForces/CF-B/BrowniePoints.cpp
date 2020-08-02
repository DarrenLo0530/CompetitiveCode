#include <bits/stdc++.h>
using namespace std;
int getQuadrant(pair<int, int> lines, pair<int, int> point){
    if(point.first > lines.first && point.second > lines.second){
        return 1;
    } else if(point.first < lines.first && point.second < lines.second){
        return 3;
    } else if(point.first != lines.first && point.second != lines.second){
        return 2;
    }
    return -1;

}

int main(){
    while(true){
        vector<pair<int, int>> pnts;
        int n;
        scanf("%d", &n);

        if(n == 0){
            break;
        }

        pair<int, int> lines;

        for(int i = 1; i<=n; i++){
            int x, y;
            
            scanf("%d%d", &x, &y);
            if(i == (1 + (double)n)/2){
                lines = {x, y};
            } else {
                pnts.push_back({x, y});
            }
        }
        int o = 0;
        int s = 0;

        for(auto pnt: pnts){
            int quadrant = getQuadrant(lines, pnt);
            if(quadrant == 1 || quadrant == 3){
                s++;
            } else if(quadrant == 2) {
                o++;
            }
        }

        printf("%d %d\n", s, o);
    }
}
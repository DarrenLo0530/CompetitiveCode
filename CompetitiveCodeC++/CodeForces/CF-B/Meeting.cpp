#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<pii> rCoord;
vector<int> radius;

double calculateDistance(pii p1, pii p2){
    return sqrt((double) pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main(){
    int xa, ya, xb, yb;
    scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
    pii tl = {min(xa, xb), max(ya, yb)};
    pii br = {max(xa, xb), min(ya, yb)};

    int n;
    scanf("%d", &n);

    while(n--){
        int x, y, r;
        scanf("%d%d%d", &x, &y, &r);
        rCoord.push_back({x, y});
        radius.push_back(r);
    }

    int blankets = 0;
    for(int i = tl.first; i<=br.first; i++){
        bool found1 = false;
        bool found2 = false;
        for(int j = 0; j<rCoord.size(); j++){

            if(!found1 && radius[j] >= calculateDistance(rCoord[j], {i, tl.second})){
                found1 = true;
            }
            if(!found2 && radius[j] >= calculateDistance(rCoord[j], {i, br.second})){
                found2 = true;
            }
        }
        if(!found1){
            blankets++;
        }
        if(!found2){

            blankets++;
        }
    }

    for(int i = br.second + 1; i<= tl.second-1; i++){
        bool found1 = false;
        bool found2 = false;
        for(int j = 0; j<rCoord.size(); j++){
            if(!found1 && radius[j] >= calculateDistance(rCoord[j], {tl.first, i})){
                found1 = true;
            }
            if(!found2 && radius[j] >= calculateDistance(rCoord[j], {br.first, i})){
                found2 = true;
            }
        }

        if(!found1){
            blankets++;
        }
        if(!found2){
            blankets++;
        }
    }

    printf("%d\n", blankets);
    
}

#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int main(){
    int n, k;
    scanf("%d%d", &n, &k);

    double dist = 0;
    
    int px = INF;
    int py = INF;

    while(n--){
        int cx, cy;
        scanf("%d%d", &cx, &cy);
        if(px != INF){
            dist += sqrt(pow(px - cx, 2) + pow(py - cy, 2));
        }

        px = cx;
        py = cy;
    }

    dist *= k;
    printf("%.9f", dist/50);
}
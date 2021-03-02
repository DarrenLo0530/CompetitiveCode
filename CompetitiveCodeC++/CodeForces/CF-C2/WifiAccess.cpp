#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int xr[101], yr[101], r[101];
int n, y;


int sqr(int x){
    return x*x;
}

bool inRangeOne(int x1, int y1, int r1, int x2, int y2){
    int dist = sqr(x1 - x2) + sqr(y1 - y2);
    return dist <= sqr(r1);
} 

bool inRangeAll(int x, int y){
    for(int i = 0; i<n; i++){
        if(inRangeOne(xr[i], yr[i], r[i], x, y)){
            return true;
        }
    }
    return false;
    
}
int main(){
    int t;
    scanf("%d", &t);
    for(int c = 1; c<=t; c++){
        scanf("%d%d", &n, &y);
        for(int i = 0; i<n; i++){
            scanf("%d%d%d", xr + i, yr + i, r + i);
        }

        printf("Case %d:\n", c);
        for(int i = 0; i<y; i++){
            int x, y;
            scanf("%d%d", &x, &y);
            printf(inRangeAll(x, y) ? "Yes\n" : "No\n");
        }
    }
}
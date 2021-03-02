#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int n;
pii p[101], q[101];

int orientation(int x1i, int y1i, int x2i, int y2i, int x3i, int y3i){
    int ori = (y2i-y1i)*(x3i-x2i) - (x2i-x1i)*(y3i-y2i);
    if(ori == 0){
        return 0;
    } else if(ori > 0){
        return 1;
    }

    return 2;
}

bool inSegment(int x1i, int y1i, int x2i, int y2i, int x3i, int y3i){
    return x3i >= min(x1i, x2i) && x3i <= max(x1i, x2i) && y3i >= min(y1i, y2i) && y3i <= max(y1i, y2i);
}


bool intersects(int f, int s){
    int o1 = orientation(p[f].first, p[f].second, q[f].first, q[f].second, p[s].first, p[s].second);
    int o2 = orientation(p[f].first, p[f].second, q[f].first, q[f].second, q[s].first, q[s].second);
    int o3 = orientation(p[s].first, p[s].second, q[s].first, q[s].second, p[f].first, p[f].second);
    int o4 = orientation(p[s].first, p[s].second, q[s].first, q[s].second, q[f].first, q[f].second);

    if(o1 != o2 && o3 != o4){
        return true;
    }

    if(o1 == 0 && inSegment(p[f].first, p[f].second, q[f].first, q[f].second, p[s].first, p[s].second)){
        return true;
    }
    if(o2 == 0 && inSegment(p[f].first, p[f].second, q[f].first, q[f].second, q[s].first, q[s].second)){
        return true;
    }
    if(o3 == 0 && inSegment(p[s].first, p[s].second, q[s].first, q[s].second, p[f].first, p[f].second)){
        return true;
    }
    if(o4 == 0 && inSegment(p[s].first, p[s].second, q[s].first, q[s].second, q[f].first, q[f].second)){
        return true;
    }

    return false;    
}

bool isIsolated(int c){
    for(int i = 0; i<n; i++){
        if(i == c){
            continue;
        }

        if(intersects(i, c)){
            return false;
        }
    }

    return true;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);


        for(int i = 0; i<n; i++){
            scanf("%d%d%d%d", &p[i].first, &p[i].second, &q[i].first, &q[i].second);
        }
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(isIsolated(i)){
                ans++;
            }
        }

        printf("%d\n", ans);


    }
}
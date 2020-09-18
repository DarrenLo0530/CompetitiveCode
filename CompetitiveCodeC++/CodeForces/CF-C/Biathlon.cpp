#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
int ans[10010];
struct target{
    int x, r, i;
    bool operator <(const target &t1) const {
        return x < t1.x;
    }
};

ll dist(int x, int y, int x2, int y2){
    return (ll) pow(x - x2, 2) + pow(y - y2, 2);
}

int main(){
    memset(ans, -1, sizeof(ans));
    int n;
    scanf("%d", &n);

    vector<target> circles;
    for(int i = 0; i<n; i++){
        int x, r;
        scanf("%d%d", &x, &r);
        circles.push_back(target{x, r, i});
    }

    sort(circles.begin(), circles.end());

    int numHit = 0;
    int m;
    scanf("%d", &m);
    for(int i = 1; i<=m; i++){
        int x, y;
        scanf("%d%d", &x, &y);

        auto left = upper_bound(circles.begin(), circles.end(), target{x, INF, INF});
        if(left != circles.begin()){
            --left;
        }
        for(int j = 0; j<=1 && left != circles.end(); j++){
            int targetX = left->x;
            int radius = left->r;
            int number = left->i;
            ll distBetween = dist(x, y, targetX, 0);
            if(distBetween <= (radius*radius)){
                if(ans[number] == -1){
                    ans[number] = i;
                    ++numHit;
                }
            }
            ++left;
        }
    }

    printf("%d\n", numHit);
    for(int i = 0; i<n; i++){
        if(i != 0){
            printf(" ");
        }
        printf("%d", ans[i]);
    }
}
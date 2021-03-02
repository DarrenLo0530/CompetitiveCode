#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

struct Circle {
    double x, y, r;
};

Circle circles[201];
vector<int> adj[201];
bool visited[201];

int dfs(int i){
    visited[i] = true;
    int ans = 1;

    for(int j: adj[i]){
        if(!visited[j]){
            ans += dfs(j);
        }
    }
    return ans;
}

bool intersects(Circle &c1, Circle &c2){
    double d = sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
    return c1.r + c2.r > d && !(d + min(c1.r, c2.r) <= max(c1.r, c2.r));
}
int main(){
    int n;
    while(true){
        memset(visited, false, sizeof(visited));
        for(int i = 0; i<=200; i++){
            adj[i].clear();
        }

        scanf("%d", &n);

        if(n == -1){
            break;
        }

        for(int i = 0; i<n; i++){
            double x, y, r;
            scanf("%lf%lf%lf", &x, &y, &r);
            circles[i] = Circle{x, y, r};
        }

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(intersects(circles[i], circles[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                ans = max(ans, dfs(i));
            }
        }

        if(ans == 1){
            printf("The largest component contains %d ring.\n", ans);
        } else {
            printf("The largest component contains %d rings.\n", ans);
        }


        
    }
}
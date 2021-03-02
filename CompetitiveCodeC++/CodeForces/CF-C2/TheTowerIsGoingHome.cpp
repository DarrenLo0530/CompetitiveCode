#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int lineEnd[100005];
vector<int> x;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i<n; i++){
        int vert;
        scanf("%d", &vert);
        x.push_back(vert);
    }
    x.push_back(0);
    x.push_back(1e9);
    sort(x.begin(), x.end());

    int total = 0;
    for(int i = 0; i<m; i++){
        int x1, x2, y;
        scanf("%d%d%d", &x1, &x2, &y);
        if(x1 == 1){
            total++;
            int end = --upper_bound(x.begin(), x.end(), x2) - x.begin();
            lineEnd[end]++;
        } 
    }

    int ans = INF;
    int removed = 0;
    for(int i = 0; i<=n; i++){
        removed+=lineEnd[i];
        ans = min(ans, total - removed + i);
    }
    printf("%d\n", ans);
}
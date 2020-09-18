#include <bits/stdc++.h>
using namespace std;
int nodes[501];
int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 1; i<=n; i++){
        scanf("%d", nodes + i);
    }
    double ans = 0;
    for(int i = 0; i<m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        ans = max(ans, (double)(nodes[a] + nodes[b])/ c);
    }

    printf("%.15lf", ans);

}
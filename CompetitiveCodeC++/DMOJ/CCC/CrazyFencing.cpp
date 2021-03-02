#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int MX = 1e4 + 10;
int heights[MX];
int widths[MX];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i<=n; i++) {
        scanf("%d", &heights[i]);
    }

    for(int i = 1; i <= n; i++) {
        scanf("%d", &widths[i]);
    }

    double ans = 0;
    for(int i = 1; i<=n; i++) {
        ans += (double) widths[i] * (((double) heights[i-1] + heights[i]) / 2.0);
    }

    printf("%.2f", ans);
}
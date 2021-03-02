#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    double ans = 0;
    
    for(int i = 1; i<=m; i++){
        double prob = pow(i/(double)m, n) - pow((i-1)/(double)m, n);
        ans += prob * i;
    }

    cout << fixed << setprecision(12) << ans << '\n';
}
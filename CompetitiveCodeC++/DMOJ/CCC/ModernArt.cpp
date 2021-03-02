#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;


int main(){
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);

    vector<int> rows(m+10, 0);
    vector<int> cols(n+10, 0);

    for(int i = 0; i<k; i++) {
        char c;
        int x;
        scanf(" %c%d", &c, &x);
        if(c == 'R') {
            rows[x]++;
        } else {
            cols[x]++;
        }
    }

    int ans = 0;
    for(int i = 1; i<=m; i++) {
        for(int j = 1; j<=n; j++) {
            if((rows[i] + cols[j]) % 2 != 0) {
                ans++;
            }
        }
    }

    printf("%d\n", ans);
}
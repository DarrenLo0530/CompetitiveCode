#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;

int n[2];
int c[2][6];
int a, b;

ld epsilon = 1e-9;


ld f(int j, ld x) {
    ld ans = 0;
    for(int i = n[j]; i>=0; i--) {
        ans *= x;
        ans += c[j][i];
    }

    return ans;
}

ld solve() {
    ld l = a;
    ld r = b;
    ld mid = 0;

    while(!(r - l < epsilon)) {
        mid = (l + r)/2.0;
        if(f(0, mid) > f(1, mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    return (r + l)/2.0;
}

int main(){
    for(int i = 0; i<2; i++){
        scanf("%d", &n[i]);
        for(int j = n[i]; j>=0; j--) {
            scanf("%d", &c[i][j]);
        }
    }



    scanf("%d%d", &a, &b);

    if(f(0, a) > f(1, a) || f(0, b) < f(1, b)) {
        swap(n[0], n[1]);
        swap(c[0], c[1]);
    }
    cout << fixed << setprecision(10) << solve();
}
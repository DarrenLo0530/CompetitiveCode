#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<double, double> pdd;

const int MX = 1e3 + 4;
ld x[MX], y[MX];

const ld eps = 1e-6;

ld sqr(ld x) {
    return x*x;
}

int main(){
    int n;
    scanf("%d", &n);    
    for(int i = 0; i<n; i++){
        scanf("%Lf%Lf", &x[i], &y[i]);
    }

    for(int i = 0; i<n; i++) {
        ld l = 0;
        ld r = 1000;
        bool lower = false;

        for(int j = 0; j<n; j++) {
            if(i == j) {
                continue;
            }

            if(x[i] == x[j]) {
                if(y[j] < y[i]) {
                    lower = true;
                    break;
                }
            } else {
                ld mid = (sqr(x[i]) + sqr(y[i]) - sqr(x[j]) - sqr(y[j])) / (2*(x[i] - x[j]));
                if(x[j] < x[i]) {
                    l = max(mid, l);
                } else {
                    r = min(mid, r);
                }
            }
        }        

        if(!lower && l <= r + eps) {
            printf("The sheep at (%.2Lf, %.2Lf) might be eaten.\n", x[i], y[i]);
        }

    }

}
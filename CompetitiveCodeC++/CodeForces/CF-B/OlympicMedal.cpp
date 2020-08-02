#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    int mxOuter = 0;
    int mxp1 = 0;
    int mnp2 = 0x3f3f3f3f;

    while(n--){
        int x;
        scanf("%d", &x);
        mxOuter = max(mxOuter, x);
    }

    int m;
    scanf("%d", &m);
    while(m--){
        int x;
        scanf("%d", &x);
        mxp1 = max(mxp1, x);
    }

    int k;
    scanf("%d", &k);
    while(k--){
        int x;
        scanf("%d", &x);
        mnp2 = min(mnp2, x);
    }

    int a, b;
    scanf("%d%d", &a,&b);

    double ans = sqrt(b*mxp1*pow(mxOuter, 2) / (a*mnp2 + b*mxp1));


    printf("%.12f", ans);

}
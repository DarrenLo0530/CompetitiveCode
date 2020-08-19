#include <bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        int n, m;
        scanf("%d%d", &n, &m);
        if(n == 0 && m == 0){
            break;
        }
        double ans = (double)(m + 1 - n)/(m + 1);
        if(m < n){
            ans = 0;
        }
        printf("%.6f\n", ans);
    }
}
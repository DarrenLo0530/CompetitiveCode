#include <bits/stdc++.h>
using namespace std;

int main(){
    int s;
    cin >> s;
    for(int i = 0; i<s; i++){
        int n, m;
        double p;
        cin >> n >> p >> m;
        double cnt = pow(1 - p, m - 1);
        double ans = 0;
        while(true){
            if(cnt * p < 0.000001){
                break;
            }
            ans += cnt * p;
            cnt *= pow(1-p, n);
        }

        printf("%.4f\n", ans);
    }
}
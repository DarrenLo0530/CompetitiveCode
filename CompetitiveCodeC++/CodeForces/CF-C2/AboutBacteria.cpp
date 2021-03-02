#include <bits/stdc++.h>
using namespace std;
 
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
 
int main(){
    ll k, b, n, t;
    scanf("%lld%lld%lld%lld", &k, &b, &n, &t);
    int ans;
    if(k == 1){
        ans = ceil((1 + n*b - t)/(double)b);
        ans = max(ans, 0);
    } else {
        for(ans = n; ans >= 0; ans--){
            if(!(pow(k, n-ans) <= ((t*k - t + b)/(double)(k-1+b)))){
                break;
            }
        }
        ans = max(0, ans+1);
    }
 
    printf("%d\n", ans);
}
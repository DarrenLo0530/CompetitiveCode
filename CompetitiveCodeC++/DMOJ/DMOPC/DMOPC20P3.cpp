#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int s[500001];

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        scanf("%d", s + i);
    }

    int maxIdx = 0;
    int maxNum = -INF;
    for(int i = 0; i<n; i++){
        if(s[i] >= maxNum){
            maxNum = s[i];
            maxIdx = i;
        }
    }

    ll ans = 0;
    bool increasing = true;
    for(int i = 1; i<maxIdx; i++){
        ans += max(0, s[i-1] - s[i]);
        s[i] += max(0, s[i-1] - s[i]);
    }

    for(int i = n-2; i > maxIdx; i--){
        ans += max(0, s[i+1] - s[i]);
        s[i] += max(0, s[i+1] - s[i]);
    }

    printf("%lld\n", ans);
}
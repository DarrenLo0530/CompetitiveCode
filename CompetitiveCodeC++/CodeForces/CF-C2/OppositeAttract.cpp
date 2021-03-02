#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int cnt[30];
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int x;
        scanf("%d", &x);
        cnt[x + 10]++;
    }
    ll ans = 0;
    for(int i = 10; i<=20; i++){
        if(i == 10){
            ans += ((ll)cnt[i]*(cnt[i]-1))/2;
        } else {
            ans += (ll)cnt[i]*(cnt[-(i - 10) + 10]);
        }
    }

    cout << ans << "\n";

}
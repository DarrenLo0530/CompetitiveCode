#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int cnt=0;
    while(true){
        ll a, b;
        scanf("%lld%lld", &a, &b);
        if(a == 0 && b == 0){
            break;
        }
        ll ans = b*(b-1)/2 * ((a*(a-1))/2);
        /*
        ll sum = b*(b-1)/2;
        ll ans = 0;
        for(int i = 1; i<=a; i++){
            ll remaining = a - i;
            ans += sum*remaining;
        }
        */
        printf("Case %d: %lld\n", ++cnt, ans);
    }

}
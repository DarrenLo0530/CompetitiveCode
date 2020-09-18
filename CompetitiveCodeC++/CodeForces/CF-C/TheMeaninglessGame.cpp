#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> perfectCubes;
int main(){
    for(ll i = 0; i<=1000001; i++){
        perfectCubes.push_back(i*i*i);
    }

    int n;
    scanf("%d", &n);
    
    while(n--){
        ll a, b;
        scanf("%lld%lld", &a, &b);
        auto pos = lower_bound(perfectCubes.begin(), perfectCubes.end(), a*b);
        if(*pos == a*b){
            ll cb = pos - perfectCubes.begin();
            if(a % cb == 0 && b % cb== 0){
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        } else {
            printf("No\n");
        }
    }
}
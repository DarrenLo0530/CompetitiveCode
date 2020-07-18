#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pows[100];

int main(){
    ll b, p, m;
    while(cin >> b){
        cin >> p >> m;
    
        pows[0] = b % m;
        for(int i = 1; i <= 31; i++){
            pows[i] = (pows[i-1] * pows[i-1]) % m;
        }


        ll ans = 1;
        for(int i = 0; i<=31; i++){
            if((1 << i) & p){
                ans *= pows[i];
                ans %= m;
            }
        }

        printf("%d\n", ans);
    }

}
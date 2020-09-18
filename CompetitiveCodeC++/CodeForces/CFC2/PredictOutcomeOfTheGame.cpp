#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        ll n, k, d1, d2;

        scanf("%lld%lld%lld%lld" , &n, &k, &d1, &d2);
        if(n % 3 != 0){
            cout<<"no\n";
            continue;
        }

        ll gamesRem = n-k;
        bool poss = false;
        for(int sign1 = -1; sign1 <= 1; sign1 += 2){
            for(int sign2 = -1; sign2 <= 1; sign2 += 2){

                ll x1 = (sign1*d1*2 + sign2*d2 + k) / 3;
                ll x3 = sign1*d1 + k - 2*x1;
                ll x2 = k - x1 - x3; 

                if(abs(x1 - x2) != d1 || abs(x2 - x3) != d2 || x1 + x2 + x3 != k){
                    continue;
                }

                if(x1 <= n/3 && x1 >= 0 && x2 >= 0 && x2 <= n/3 && x3 >= 0 && x3 <= n/3){
                    poss = true;
                }
            }
        }

        if(poss){
            printf("yes\n");
        } else {
            printf("no\n");
        }
        
    }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll p, d;
    cin >> p >> d;



    ll digitCounter = 1;
    while(true){
        ll temp = p/digitCounter;
        if(temp % 10 != 9){
            d -= ((temp%10) + 1) * digitCounter;
            if(d < 0){
                break;
            }

            p -= ((temp%10) + 1) * digitCounter;
        }

        digitCounter *= 10;


    }

    cout<<p<<'\n';

}
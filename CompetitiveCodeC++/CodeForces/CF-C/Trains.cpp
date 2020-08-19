#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

set<ll> at, bt;

int main(){
    ll a, b;
    scanf("%lld%lld", &a, &b);  
    ll end = a*b/__gcd(a, b);
    ll aCounter = a;
    ll aTime = 0;

    while(true){
        if(aCounter > end){
            break;
        }

        if(aCounter == end){
            ll prev = max(aCounter - a, aCounter - b);
            if(a > b){
                aTime += (aCounter - prev);
            }
        } else {
            ll prev = max(aCounter - a, b * (aCounter/b));
            aTime += (aCounter - prev);
        }
        aCounter += a;
    }       

    //cout<<aTime<<'\n';
    if(aTime > end-aTime){
        cout<<"Dasha"<<'\n';
    } else if(aTime < end - aTime){
        cout<<"Masha"<<'\n';
    } else {
        cout<<"Equal"<<'\n';
    }
}
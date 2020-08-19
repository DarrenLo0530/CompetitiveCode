#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isPrime(ll x){
    if(x == 1){
        return false;
    }
 
    for(int i = 2; i<=(ll)sqrt(x); i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}
 
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        ll x;
        scanf("%lld", &x);
 
        if((double) sqrt(x) == (ll) sqrt(x) && isPrime(sqrt(x))){
            cout<<"YES"<<'\n';
        } else {
            cout<<"NO"<<'\n';
        }
    }
}

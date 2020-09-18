#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MX = 1000000000000000000;
vector<ll> knockedOut;
int main(){
    knockedOut.push_back(1);
    knockedOut.push_back(2);
    for(int i = 2;; i++){
        ll next = knockedOut[i-1] + knockedOut[i-2];
        knockedOut.push_back(next);
        if(next > MX){
            break;
        }
    }
    ll n;
    if(n == 0){
        cout<<0<<'\n';
        return 0;
    }
    scanf("%lld", &n);
    int pos = --upper_bound(knockedOut.begin(), knockedOut.end(), n) - knockedOut.begin();
    cout<<pos<<'\n';
}
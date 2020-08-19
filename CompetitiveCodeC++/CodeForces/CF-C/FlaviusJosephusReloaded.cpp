#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, a, b;

    while(true){
        set<ll> visited;

        cin >> n;
        if(n == 0){
            break;
        }

        cin >> a >> b;
        ll prev = 0;
        ll ans = n;
        map<ll, ll> cnt;
        while(true){
            cnt[prev]++;
            if(cnt[prev] == 2){
                ans--;
            } else if(cnt[prev] == 3){
                break;
            }

            prev = (a * ((prev * prev % n)) + b) % n;
        }

        cout<<ans<<'\n';
    }
}
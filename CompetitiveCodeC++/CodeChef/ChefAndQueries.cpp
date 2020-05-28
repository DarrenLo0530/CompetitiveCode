#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const unsigned int mx = (1LL << 32) - 1;

bitset<mx> vis;


int main(){

    ll Q;
    unsigned int s1, a, b;
    cin >> Q >> s1 >> a >> b;

    ll count = Q;
    ll ans = 0;

    while(count > 0){
        if(count != Q) {
            s1 = (a*s1 + b);
        }

        if(s1 % 2 != 0){
            if(!vis[s1/2]){
                vis[s1/2] = true;
                ans += s1/2;

            }
            
        } else {
            if(vis[s1/2]){
                vis[s1/2] = false;
                ans -= s1/2;
            }
        }
        count--;
    }

    
    
    cout<<ans;
}
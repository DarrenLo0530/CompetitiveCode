#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll m = 1e9+7;
ll nk[3000][3000];

ll modExpo(ll b, ll p){
    ll ret = 1;
    while(p > 0){
        if(p % 2 != 0){
            ret = (ret * b) % m;        
        }
        p/=2;
        b = (b * b) % m;
    }

    return ret;
}

int main(){
    ll n, k;
    scanf("%lld%lld", &n, &k);
    for(int i = 0; i<3000; i++){
        nk[i][0] = 1;
        for(int j = 1; j<=i; j++){
            nk[i][j] = (nk[i-1][j-1] + nk[i-1][j]) % m;
        }
    }

    //Start with all possible colourings
    ll ans = (k * modExpo(k-1, n-1)) % m;
    //Exclusion inclusion principle
    //Subtract colourings that only use k-1 OR k-2 OR k-3 ...
    //That is subtract graphs that use k-1, add those that use k-2 AND k-1 which is just those that use k-2
    //then add graphs that use k-1 AND k-2 AND k-3 which is equivelant to those that use k-3
    //then subtract graphs that use k-1 AND k-2 AND k-3 AND k-4 which is equivelant to k-4
    //Let's say you are making a graph only using k-i colours. Then you must choose i colours to not use. There are k choose i combinations of these i colours.
    //Therefore there are (k choose i) number of graphs that only use k-i of the colours. Therefore multiply the number of ways to paint a graph with k-i colours by k choose i.
    
    for(ll i = 1; i<k-1; i++){
        //Up to i = k-2, since
        ll sign = 1;
        if(i % 2 != 0){
            sign = -1;
        }
        ans = (ans + ((sign * (k - i) * nk[k][i]) % m * modExpo(k-i-1, n-1)) % m + m) % m;       
    }

    cout<<ans<<'\n';
    return 0;   

}
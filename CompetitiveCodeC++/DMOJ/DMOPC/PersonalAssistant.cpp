#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//What matters:
//Last anime watched(time ended)
const int mx = 10e5 + 15;
ll dp[mx]; //max hapiness if u watched n anime

//dp[i] = max(dp[0] .. dp[k]) where k is last anime possibly watched if dp
ll l[mx], r[mx], h[mx];
ll n;

int binarySearch(int ls, int rs, ll v){
    if(ls >= rs){
        return ls;
    }

    int m = (ls + rs)/2;

    if (r[m] >= v){
        return binarySearch(ls, m, v);
    } else {
        return binarySearch(m+1, rs, v);
    }

}

int main(){
    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        scanf("%lld%lld%lld", r+i, l+i, h+i);
    }

    
 
    for(int i = n-1; i>=0; i--){
        int next = binarySearch(i+1, n, r[i] + l[i]);

        if(next == n || r[next] < r[i] + l[i]){
            //No anime after u can watch
            dp[i] = max(dp[i+1], h[i]);        
        } else {
            for(int x = next-1; x>i; x++){
                if(x != next){
                    break;
                } else {
                    next = x;
                }
            }
            dp[i] = max(dp[i+1], h[i] + dp[next]); 
        }
    }



    cout<<dp[0];


}
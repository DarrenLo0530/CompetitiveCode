#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int m = 1e9 + 7;

int main(){
    int n;
    scanf("%d", &n);
    ll numWays = 1;
    for(int i = 0; i < 3*n; i++){
        numWays = (numWays * 3) % m;
    }

    ll numBad = 1;
    for(int i = 0; i<n; i++){
        numBad = (numBad * 7) % m;
    }

    ll ans = (numWays - numBad + m) % m;
    printf("%lld\n", ans);


    

}
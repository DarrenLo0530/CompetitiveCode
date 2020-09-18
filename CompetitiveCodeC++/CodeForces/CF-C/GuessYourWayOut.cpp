#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char mv[2] = {'L', 'R'};
int main(){
    ll h, n;
    scanf("%lld%lld", &h, &n);
    n += pow(2, h) - 1;
    ll numNodes = pow(2, h+1) -1;
    string dir = "";
    while(n != 1){
        if(n % 2 == 0){
            dir = "L" + dir;
        } else {
            dir = "R" + dir;
        }

        n/=2;
    }

    ll ans = 0;
    int curr = 0;
    for(char d: dir){
        ans++;
        numNodes /= 2;
        if(d == mv[curr]){
            curr ^= 1;
        } else {
            ans += numNodes;
        }
    }

    printf("%lld\n", ans);
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    while(true){
        ll sz, p;
        scanf("%lld%lld", &sz, &p);
        if(sz == 0 && p == 0){
            break;
        }

        ll ring = ceil((double) sqrt(p))/2;
        ll length = ring*2 + 1;
        ll tr = length*length;
        ll bl = (length-1)*(length-1) + 1;
        ll tl = ((length-2) * (length-2) + bl)/ 2;
        ll br = (tr + bl)/2;

        ll x = ring + (sz+1)/2;
        ll y = x;
        if(p >= bl & p <= br){
            y = y - (tr - br);
            x = x - (br - p);
        } else if(p <= tr && p >= br){
            y = y - (tr - p);
        } else if(p >= tl && p <= bl){
            x = x - (length - 1);
            y = y - (p - tl);
        } else {
            x = x - (length - (tl - p)) + 1;
        }

        printf("Line = %lld, column = %lld.\n", y, x);
    }
}
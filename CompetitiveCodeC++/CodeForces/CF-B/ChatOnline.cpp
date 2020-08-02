#include <bits/stdc++.h>
using namespace std;
bitset<3001> z, x;
int main(){
    int p, q, l, r;
    scanf("%d%d%d%d", &p, &q, &l, &r);

    while(p--){
        int a, b;
        scanf("%d%d", &a, &b);
        for(int i = a; i<=b; i++){
            z[i] = true;
        }
    }

    while(q--){
        int a, b;
        scanf("%d%d", &a, &b);
        for(int i = a; i<=b; i++){
            x[i + l] = true;
        }
    }

    int ans = 0;
    for(int i = l; i<=r; i++){
        if((z & x).count()){
            ans++;
        }

        x = x << 1;
    }

    printf("%d\n", ans);

}
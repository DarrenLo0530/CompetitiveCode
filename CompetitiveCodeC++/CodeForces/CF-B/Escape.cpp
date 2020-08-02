#include <bits/stdc++.h>
using namespace std;

int main(){
    int vp, vd, t, f, c;
    scanf("%d%d%d%d%d", &vp, &vd, &t, &f, &c);

    int ans = 0;
    double princessDist = t * vp;
    if(vp > vd){
        cout<<"0"<<'\n';
        return 0;
    }
    while(true){
        double dragonTime = princessDist/(vd - vp);
        princessDist += vp * dragonTime;
        if(princessDist >= c){
            break;
        }

        ans++;
        princessDist += vp * (dragonTime + f);
    }

    printf("%d\n", ans);

}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, c, s, e;
    //1ebs2ebs3ebs4ebs
    scanf("%d%d%d%d", &t, &c, &s, &e);
    if(s == e){
        printf("%d", t);
    } else if(s < e){
        int ans = (e - s - 1) * (t+2*c) + 2*c;
        printf("%d", ans);
    } else {
        int ans = (s - e + 1) * (t+2*c) - 2*c;
        printf("%d", ans);

    }
}
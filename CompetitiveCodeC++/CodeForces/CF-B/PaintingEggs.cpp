#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);


    string ans = "";
    int am = 0, gm = 0;
    for(int i = 0; i<n; i++){
        int a, g;
        scanf("%d%d", &a, &g);
        int givea = abs(am + a - gm);
        int giveg = abs(gm + g - am);

        if(givea < giveg){
            am += a;
            ans+="A";
        } else {
            gm += g;
            ans += "G";
        }
    }

    if(abs(am - gm) > 500){
        cout<<"-1";
    } else {
        cout<<ans;
    }
}
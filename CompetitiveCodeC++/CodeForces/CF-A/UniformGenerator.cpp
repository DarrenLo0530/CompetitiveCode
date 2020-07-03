#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    while(cin >> a){
        cin >> b;
        //Good if lcm is not a*b, bad else good
        if(__gcd(a, b) == 1){
            printf("%d%dGoodChoice\n", a, b);
        } else {
            printf("%d%dBadChoice\n", a, b);
        }

        cout << "\n";

    }

}
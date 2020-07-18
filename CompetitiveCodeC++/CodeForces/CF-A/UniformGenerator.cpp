#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    while(cin >> a){
        cin >> b;
        //Good if lcm is not a*b, bad else good
        if(__gcd(a, b) == 1){
            printf("%10d%10d    Good Choice\n", a, b);
        } else {
            printf("%10d%10d    Bad Choice\n", a, b);
        }

        cout << "\n";

    }

}
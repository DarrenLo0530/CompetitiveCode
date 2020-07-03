#include <bits/stdc++.h>
using namespace std;
int main(){
    while(true){
        int x;
        scanf("%d", &x);
        if(x == 0){
            break;
        }
        
        int e = (int) sqrt(x);
        if(e*e == x){
            cout << "yes" << "\n";
        } else {
            cout << "no" << "\n";
        }
    }
}
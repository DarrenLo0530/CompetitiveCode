#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n >= 7){
        cout << "ROYGBIV";
        n -= 7;
    }

    

    string end = "GBIV";
    for(int i = 0; i<n; i++){
        cout << end[i % 4];
    }

    cout << "\n";
}
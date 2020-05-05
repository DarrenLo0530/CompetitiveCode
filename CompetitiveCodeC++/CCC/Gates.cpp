#include <bits/stdc++.h>
using namespace std;
set<int> gates;


int main(){
    int G, P, p;
    scanf("%d %d", &G, &P);
    for(int i = 1; i<=G; i++){
        gates.insert(i);
    }

    for(int i = 0; i<P; i++){
        scanf("%d", &p);
        auto up = gates.upper_bound(p);

        if(up != gates.begin()){
            --up;
            gates.erase(*up);
        } else {
            cout<<i;
            return 0;
        }
    }

    cout<<P;
    return 0;



    

}
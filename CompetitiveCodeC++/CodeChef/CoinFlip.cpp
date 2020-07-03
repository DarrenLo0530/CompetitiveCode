#include <bits/stdc++.h>
using namespace std;

void solve(){
    int g;
    scanf("%d", &g);
    while(g--){
        int i, n, q;

        scanf("%d%d%d", &i, &n, &q);
        int numSame = n/2;
        int numDiff = n - numSame;

        if(i == q){
            cout << numSame << '\n';
        } else {
            cout << numDiff << '\n';
        }
    }

}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        solve();
    }
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, p;
        scanf("%d%d", &n, &p);
        int numEdges = 2*n + p;
        for(int i = 1; i<=n; i++){
            for(int j = i+1; j<=n; j++){
                if(numEdges == 0){
                    break;
                }

                cout<<i << " " << j<<'\n';
                numEdges--;
            }
        }
    }
}
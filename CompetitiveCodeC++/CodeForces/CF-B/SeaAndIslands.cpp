#include <bits/stdc++.h>
using namespace std;



int main(){
    int n, k;
    scanf("%d%d", &n, &k);

    int maxIslands = (n*n + 1)/2;

    if(k > maxIslands){
        printf("NO\n");
    } else {
        printf("YES\n");
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0)) && k > 0){
                    k--;
                    printf("L");
                } else {
                    printf("S");
                }
            }
            cout<<'\n';
        }
    }
}
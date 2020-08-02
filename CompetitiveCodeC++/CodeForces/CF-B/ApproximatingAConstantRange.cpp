#include <bits/stdc++.h>
using namespace std;

int idx[100003];
int main(){
    int n;
    int maxDist = 0;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        int x;
        scanf("%d", &x);
        idx[x] = i;
        if(idx[x-1] > idx[x+1]){
            maxDist = max(maxDist, i - max(idx[x-2], idx[x+1]));
        } else {
            maxDist = max(maxDist, i - max(idx[x+2], idx[x-1]));
        }

    }

    printf("%d\n", maxDist);
}
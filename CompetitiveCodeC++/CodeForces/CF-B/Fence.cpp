#include <bits/stdc++.h>
using namespace std;

int fence[200000];
int main(){
    int n, k;
    scanf("%d%d", &n, &k);

    for(int i = 1; i<=n; i++){
        scanf("%d", fence + i);
        fence[i] += fence[i-1];
    }   

    int minTear = 0x3f3f3f3f;
    int minTearIdx = 0;

    for(int i = 1; i<=n; i++){
        if(i + k - 1 > n){
            break;
        }

        if(fence[i+k-1] - fence[i-1] < minTear){
            minTear = fence[i+k-1] - fence[i-1];
            minTearIdx = i;
        }
    }

    printf("%d\n", minTearIdx);
    
}
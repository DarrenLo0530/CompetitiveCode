#include <bits/stdc++.h>
using namespace std;

int problems[16];
int main(){
    int n, l, r, x;
    scanf("%d%d%d%d", &n, &l, &r, &x);

    for(int i = 0; i<n; i++){
        scanf("%d", problems + i);
    }

    int numWays = 0;
    for(int i = 0; i < (1 << n); i++){
        if(__builtin_popcount(i) < 2){
            continue;
        }

        int easiest = 0x3f3f3f3f;
        int hardest = 0;
        int total = 0;

        for(int b = 0; b < n; b++){
            
            if((1 << b) & i){
                total += problems[b];
                easiest = min(easiest, problems[b]);
                hardest = max(hardest, problems[b]);
            }
        }

        if(hardest - easiest >= x && total >= l && total <= r){
            numWays++;
        }
    }
    printf("%d\n", numWays);


    


}
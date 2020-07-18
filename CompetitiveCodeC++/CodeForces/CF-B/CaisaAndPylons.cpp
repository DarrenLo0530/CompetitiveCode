#include <bits/stdc++.h>
using namespace std;

int h[100001];
int main(){
    int n;
    scanf("%d", &n);

    for(int i = 1; i<=n; i++){
        scanf("%d", h + i);
    }

    int energy = 0;
    int energyUsed = 0;
    for(int i = 0; i<n; i++){
        energy += h[i] - h[i+1];
        if(energy < 0){
            energyUsed += energy * -1;
            energy = 0;
        }
    }
    
    printf("%d\n", energyUsed);

    
}
#include <bits/stdc++.h>
using namespace std;

vector<int> wastes;

int main(){
    int n, m, k, t;
    scanf("%d%d%d%d", &n, &m, &k, &t);

    while(k--){
        int a, b;
        scanf("%d%d", &a, &b);

        wastes.push_back((a-1)*m + b);
    }   

    sort(wastes.begin(), wastes.end());

    while(t--){
        int i, j;
        scanf("%d%d", &i, &j);
        int idx = (i-1)*m + j;
        if(*lower_bound(wastes.begin(), wastes.end(), idx) == idx){
            printf("Waste\n");
            continue;
        }
        int numWastesBefore = lower_bound(wastes.begin(), wastes.end(), idx) - wastes.begin();

        int actualIdx = idx - numWastesBefore;

        int fruit = (actualIdx - 1) % 3;
        if(fruit == 0){
            printf("Carrots\n");
        } else if(fruit == 1){
            printf("Kiwis\n");
        } else {
            printf("Grapes\n");
        }
    }

}
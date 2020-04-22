#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, l;
int x[100001], y[100001];

int main(){
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        int ans = 0;
        scanf("%d", &l);
        for(int j = 0; j<l; j++){
            scanf("%d", &x[j]);
        }
        for(int j = 0; j<l; j++){
            scanf("%d", &y[j]);
        }

        for(int j = 0; j<l; j++){
            if(j == 0 || x[j-1] != x[j]){
                int k = j;
                while(k<l && y[k] >= x[j]){
                    k++;
                }
                ans = max(ans, k-1-j);
            }
        }

        printf("The maximum distance is %d\n", ans);
    }
}
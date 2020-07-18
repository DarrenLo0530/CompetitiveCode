#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        if(i){
            printf("\n");
        }
        int xll1, yll1, xur1, yur1, xll2, yll2, xur2, yur2;
        scanf("%d%d%d%d%d%d%d%d", &xll1, &yll1, &xur1, &yur1, &xll2, &yll2, &xur2, &yur2);
        int maxyll = max(yll1, yll2);
        int maxxll = max(xll1, xll2);
        int minyur = min(yur1, yur2);
        int minxur = min(xur1, xur2);

        if(minyur - maxyll <= 0 || minxur - maxxll <= 0){
            printf("No Overlap\n");
        } else {
            printf("%d %d %d %d\n", maxxll, maxyll, minxur, minyur);
        }
    }
}
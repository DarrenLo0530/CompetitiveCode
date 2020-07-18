#include <bits/stdc++.h>
using namespace std;

int heights[1001];
int toLeft[1001];
int toRight[1001];

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        int h;
        scanf("%d", &h);
        heights[i] = h;
    }

    toLeft[0] = 1;
    for(int i = 1; i<n; i++){
        if(heights[i] >= heights[i-1]){
            toLeft[i] = toLeft[i-1] + 1;
        } else {
            toLeft[i] = 1;
        }
    }

    for(int i = n-2; i>=0; i--){
        if(heights[i] >= heights[i+1]){
            toRight[i] = toRight[i+1] + 1;
        } else {
            toRight[i] = 0;
        }
    }

    int ans = 0;
    for(int i = 0; i<n; i++){
        ans = max(ans, toLeft[i] + toRight[i]);
    }

    printf("%d\n", ans);
}
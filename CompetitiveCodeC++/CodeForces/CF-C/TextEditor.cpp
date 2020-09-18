#include <bits/stdc++.h>
using namespace std;
int a[101];
int getCol(int r1, int c1, int r2){
    int dir = r1 < r2 ? 1 : -1;
    for(int i = r1 + dir; i != r2 + dir; i += dir){
        if(a[i] + 1 < c1){
            c1 = a[i]+1;
        }
    }

    return c1;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    for(int i = 1; i<=n; i++){
        scanf("%d", a + i);
    }

    int r1, c1, r2, c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    int ans = 0x3f3f3f3f;

    for(int i = 1; i<=n; i++){
        //Go to intermediate row, then to final row.
        int interCol = getCol(r1, c1, i);
        int finalCol = getCol(i, interCol, r2);
        int totalDist = abs(r1 - i) + abs(r2 - i) + abs(finalCol - c2);
        ans = min(totalDist, ans);
    }

    printf("%d\n", ans);
}
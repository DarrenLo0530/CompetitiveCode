#include <bits/stdc++.h>
using namespace std;
int n;
int a[500005];
int ans[500005];

int solve(int l, int r){
    if(a[l] == a[r]){
        for(int i = l; i<=r; i++){
            a[i] = a[l];
        }
    } else {
        for(int i = l; i<=(l+r)/2; i++){
            a[i] = a[l];
        }
        for(int i = (l+r)/2 + 1; i <= r; i++){
            a[i] = a[r];
        }

    }
    return (r - l)/2;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d", a + i);
    }

    int l = 0;
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(i == n-1 || a[i] == a[i+1]){
            ans = max(ans, solve(l, i));
            l = i+1;
        }
    }
    printf("%d\n", ans);
    for(int i = 0; i<n; i++){
        if(i != 0){
            printf(" ");
        }
        printf("%d", a[i]);
    }
    printf("\n");


}
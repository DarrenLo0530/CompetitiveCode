#include <bits/stdc++.h>
using namespace std;

int c[101];

int main(){
    int n, a;
    scanf("%d%d", &n, &a);

    for(int i = 1; i<=n; i++){
        scanf("%d", c+i);
    }

    int ans = 0;
    int dist = 0;
    while(a - dist >= 1 || a + dist <= n){
        if(a + dist <= n && a-dist >= 1){
            if(c[a-dist] && c[a+dist]){
                ans += 2;
            }
        } else if(a-dist >= 1 && c[a-dist]){
            ans++;
        } else if(a + dist <= n && c[a+dist]){
            ans++;
        }
        dist++;
    }

    if(c[a]){
        ans--;
    }

    printf("%d\n", ans);
}
#include <bits/stdc++.h>
using namespace std;
int a[100001];
int b[100001];

int ans[4001];

int main(){
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);

    for(int i = 1; i<=n; i++){
        int t;
        scanf("%d", &t);

        a[i] = t;
    }

    for(int i = 1; i<=m; i++){
        int t;
        scanf("%d", &t);
        b[i] = t;

    }

    while(q--){
        int l1, r1, l2, r2;
        memset(ans, 0, sizeof(ans));

        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);

        for(int i = l1; i<=r1; i++){
            ans[a[i]]++;
        }

        for(int i = l2; i<=r2; i++){
            ans[b[i]]++;
        }

        int p = 0;
        for(int i = 0; i<4001; i++){
            if(ans[i] % 2 != 0){
                p++;
            }
        }

        cout<<p<<'\n';
    }
}
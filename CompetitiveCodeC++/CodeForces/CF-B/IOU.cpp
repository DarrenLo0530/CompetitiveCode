#include <bits/stdc++.h>
using namespace std;
int n, m;

int debt[101];
int rec[101];

int main(){
    scanf("%d%d", &n, &m);

    for(int i = 0; i<m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        //a owes b c
        debt[a] += c;
        rec[b] += c;
    }

    int ans = 0;
    for(int i = 1; i<=n; i++){
        if(debt[i] > rec[i]){
            ans += debt[i] - rec[i];
        }
    }

    printf("%d\n", ans);

    

}
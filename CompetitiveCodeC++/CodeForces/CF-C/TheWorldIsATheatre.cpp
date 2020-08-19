#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll pascals[100][100];
 
void gen(){
    pascals[0][0] = 1;
    for(int i = 1; i<=70; i++){
        pascals[i][0] = 1;
        pascals[i][i] = 1;
        for(int j = 1; j<i; j++){
            pascals[i][j] = pascals[i-1][j-1] + pascals[i-1][j];
        }
    }
}



int main(){
    gen();

    int n, m, t;
    scanf("%d%d%d", &n, &m, &t);
    ll ans = 0;
    for(int i = 4; i<=t-1; i++){
        ans += pascals[n][i] * pascals[m][t-i];
    }


    cout<<ans<<'\n';

}
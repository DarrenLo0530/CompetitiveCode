#include <bits/stdc++.h>
using namespace std;
int rows[1001], cols[1001];
int grid[1001][1001];

int main(){
    for(int i = 0; i<1001; i++){
        rows[i] = cols[i] = i;
    }

    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i =1 ;i<=n; i++){
        for(int j = 1; j<=m; j++){
            scanf("%d", &grid[i][j]);
        }
    }

    for(int i = 0; i<k; i++){
        char o;
        int x, y;
        scanf(" %c%d%d", &o, &x, &y);
        if(o == 'g'){
            cout<<grid[rows[x]][cols[y]]<<'\n';
        } else if(o == 'r'){
            swap(rows[x], rows[y]);
        } else {
            swap(cols[x], cols[y]);
        }
    }
}
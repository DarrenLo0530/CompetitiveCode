#include <bits/stdc++.h>
using namespace std;

int rowStart[2005];
int rowStart2[2005];
int main(){
    int n;
    scanf("%d", &n);
    long long ans = 0;
    for(int i = 0; i<n; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        rowStart[x + y]++;
        rowStart2[1000 - x + y]++;
    }

    for(int i = 0; i<2005; i++){
        ans += (rowStart[i]) * (rowStart[i] - 1) /2;
        ans += (rowStart2[i])* (rowStart2[i] - 1) /2;

    }

    cout<<ans;
    
}
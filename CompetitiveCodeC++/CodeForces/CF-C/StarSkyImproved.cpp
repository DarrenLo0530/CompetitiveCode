#include <bits/stdc++.h>
using namespace std;

int psa[11][101][101];

int main(){
    int n, q, c;
    scanf("%d%d%d", &n, &q, &c);
    for(int i = 0; i<n; i++){
        int x, y, s;
        scanf("%d%d%d", &x, &y, &s);
        psa[s][y][x]++;
    }

    for(int j = 0; j<=c; j++){
        for(int y = 1; y<=100; y++){
            for(int x = 1; x<=100; x++){
                psa[j][y][x] += psa[j][y-1][x] + psa[j][y][x-1] - psa[j][y-1][x-1];
            }
        }
    }

    for(int i = 0; i<q; i++){
        int t,x1,y1,x2,y2;
        scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
        int ans = 0;
        for(int j = 0; j<=c; j++){
            ans += ((t+j) % (c+1)) * (psa[j][y2][x2] - psa[j][y2][x1-1] - psa[j][y1-1][x2] + psa[j][y1-1][x1-1]);
        }
        cout<<ans<<'\n';
    }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int brightness[11][101][101];
int psa[11][101][101];
int main(){
    int n, q, c;
    scanf("%d%d%d", &n, &q, &c);

    for(int i = 0; i<n; i++){
        int x, y, s;
        scanf("%d%d%d", &x, &y, &s);
        for(int j = 0; j<=c; j++){
            brightness[j][y][x] += (s+j) % (c+1);            
        }
    }

    for(int j = 0; j<=c; j++){
        for(int y = 1; y<=100; y++){
            for(int x = 1; x<=100; x++){
                psa[j][y][x] += psa[j][y][x-1] + brightness[j][y][x];
            }
        }
    }
    
    for(int i = 0; i<q; i++){
        ll ans = 0;
        int t, x1, y1, x2, y2;
        scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
        if(t > c){
            t %= (c+1);
        }

        for(int i = y1; i<=y2; i++){
            ans += psa[t][i][x2] - psa[t][i][x1-1];
        }
        cout<<ans<<'\n';
    }
    
}
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

pair<int, int> art[2001];
int dp[2001][2001];
int dp2[2001][2001];

int dist(pair<int, int> p1, pair<int, int> p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main(){
    int N;
    for(int i = 0; i<2001; i++){
        for(int j = 0; j<2001; j++){
            dp[i][j] = INF;
            dp2[i][j] = INF;
        }
    }

    scanf("%d", &N);

    int Hx, Hy, Ax, Ay;
    scanf("%d%d%d%d", &Hx, &Hy, &Ax, &Ay);

    for(int i = 1; i<=N; i++){
        int x, y;
        scanf("%d%d", &x, &y);

        art[i] = make_pair(x, y);
    }

    //Active guy is A
    art[0] = make_pair(Hx, Hy);
    //dp[number of paintings caught][location of resting guy] = min movement
    dp[1][0] = dist(make_pair(Ax, Ay), art[1]);

    for(int i = 1; i<=N; i++){ //The art piece
        for(int j = 0; j<=i-1; j++){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + dist(art[i], art[i+1]));
            dp[i+1][i] = min(dp[i+1][i], dp[i][j] + dist(art[j], art[i+1]));
        }
    }

    art[0] = make_pair(Ax, Ay);
    dp2[1][0] = dist(make_pair(Hx, Hy), art[1]);
    //dp[number of paintings caught][location of resting guy] = min movement
    for(int i = 1; i<=N; i++){ //The art piece
        for(int j = 0; j<=i-1; j++){
            dp2[i+1][j] = min(dp2[i+1][j], dp2[i][j] + dist(art[i], art[i+1]));
            dp2[i+1][i] = min(dp2[i+1][i], dp2[i][j] + dist(art[j], art[i+1]));
        }
    }

    int ans = INF;
    for(int i = 0; i<N; i++){
        ans = min(ans, dp[N][i]);
        ans = min(ans, dp2[N][i]);  
    }

    cout<<ans;

    
}
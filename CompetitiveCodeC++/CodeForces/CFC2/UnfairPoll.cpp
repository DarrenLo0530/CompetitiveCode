#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

ll students[101][101];

int main(){
    ll n, m, k, x, y;
    scanf("%lld%lld%lld%lld%lld", &n, &m, &k, &x, &y);

    ll cycle = n*m + (n-2)*m;
    if(n == 1 || n == 2){
        cycle = n*m;
    }

    ll maxAsked = 2*(k/cycle), minAsked = k/cycle;
    for(int j = 1; j<=m; j++){
        students[1][j] = minAsked;
        students[n][j] = minAsked;
    }


    
    for(int i = 2; i<=n-1; i++){
        for(int j = 1; j<=m; j++){
        
            students[i][j] = maxAsked;
        }
    }

    k %= cycle;

    for(int i = 1; i<=n && k; i++){
        for(int j = 1; j<=m && k; j++){
            k--;
            students[i][j]++;
        }
    }

    for(int i = n-1; i>=1 && k; i--){
        for(int j = 1; j<=m && k; j++){
            k--;
            students[i][j]++;
        }
    }

    ll maxAns = 0LL, minAns = INFLL;
    ll s = students[x][y];
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            maxAns = max(maxAns, students[i][j]);
            minAns = min(minAns, students[i][j]);
        }
    }

    printf("%lld %lld %lld\n", maxAns, minAns, s);
}
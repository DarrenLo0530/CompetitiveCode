#include <bits/stdc++.h>
using namespace std;
bool isPrime[101000];
int up[501][501];
set<int> primes;
int main(){
    memset(isPrime, true, sizeof(isPrime));
    for(int i = 2; i<=sqrt(101000) + 1; i++){
        if(!isPrime[i]){
            continue;
        }

        for(int j = i*i; j < 101000; j += i){
            isPrime[j] = false;
        }
    }

    for(int i = 2; i<101000; i++){
        if(isPrime[i]){
            primes.insert(i);
        }
    }

    int n, m;
    scanf("%d%d", &n, &m);

    int ans = 0x3f3f3f3f;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int x;
            scanf("%d", &x);
            up[i][j] = *primes.lower_bound(x) - x;
        }
    }

    for(int i = 0; i<n; i++){
        int rowCost = 0;
        for(int j = 0; j<m; j++){
            rowCost += up[i][j];
            //cout<<up[i][j]<<" ";
        }

        //cout<<'\n';

        ans = min(ans, rowCost);
    }

    for(int i = 0; i<m; i++){
        int colCost = 0;
        for(int j = 0; j<n; j++){
            colCost += up[j][i];
        }
        ans = min(ans, colCost);

    }

    cout<<ans<<'\n';


}
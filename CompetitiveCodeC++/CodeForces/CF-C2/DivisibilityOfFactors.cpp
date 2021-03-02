#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrime[101];
int primeFac[101][101];
int ans[101];

set<int> primes;
void gen(){
    memset(isPrime, true, sizeof(isPrime));
    for(int i = 2; i<=100; i++){
        if(isPrime[i]){
            primes.insert(i);
            for(int j = i*i; j<=100; j+=i){
                isPrime[j] = false;
            }
        }
    }
}

void genPrimeFac(){
    for(int i = 1; i<=100; i++){
        int num = i;
        for(int j = 1; j<=100; j++){
            primeFac[i][j] = primeFac[i-1][j];
            if(primes.count(j)){
                while(num % j == 0){
                    num /= j;
                    primeFac[i][j]++;
                }
            }
        }
    }
}

ll solve(int n, int d){
    memset(ans, 0, sizeof(ans));
    for(int i: primes){
        int cnt = 0;
        while(d > 1 && d % i == 0){
            d/=i;
            cnt++;
        }
        ans[i] = primeFac[n][i] - cnt;
    }

    ll numFactors = 1;
    if(d <= 1){
        for(int i = 1; i<=100; i++){
            if(ans[i] < 0){
                return 0;
            }
            numFactors *= (ll)(ans[i] + 1);
        }
    } else {
        return 0;
    }
    return numFactors;
}

int main(){
    int n, d;
    gen();
    genPrimeFac();
    while(scanf("%d%d", &n, &d) == 2){
        if(!n && !d){
            break;
        }
        ll numFactors = solve(n, d);
        printf("%lld\n", numFactors);
    }   
}
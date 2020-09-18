#include <bits/stdc++.h>
using namespace std;
 
#define INF 0x3f3f3f3f
#define MX 15000000
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
int n;
int a[300001];
vector<int> primes;
bool isPrime[MX+5];
int min[MX+5];
int cnt[MX+5];
void gen(){
    memset(isPrime, true, sizeof(isPrime));
    for(ll i = 2; i<=MX; i++){
        if(isPrime[i]){ 
            primes.push_back(i);
            for(ll j = i*i; j<=MX; j += i){
                isPrime[j] = false;
            }            
        }
    }
}
 
int main(){
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d", a + i);
    }
    gen();

    int g = 0;
    for(int i = 0; i<n; i++){
        g = __gcd(a[i], g);
    }

    for(int i =0 ; i<n; i++){
        cnt[a[i] / g]++;
    }

    int ans = 0;
    for(int i = 0; i<primes.size(); i++){
        int facCnt = 0;
        for(int j = primes[i]; j<=MX; j += primes[i]){
            facCnt += cnt[j];
        }
        ans = max(facCnt, ans);
    }

    printf("%d\n", ans ? n - ans : -1);


}
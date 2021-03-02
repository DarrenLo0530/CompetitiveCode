
#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int MX = 1e6 +1;

int isPrime[MX];
int memorize[MX];
vector<int> primes;

int factor(int n){
    int ans = 0;
    for(int i = 2; i*i < MX; i++){
        while(n % i == 0){
            n/=i;
            ans++;
        }
    }
    if(n != 1){
        ans++;
    }

    return ans;
}

int main(){
    int n;
    for(int i = 2; i<MX; i++){
        memorize[i] = memorize[i-1] + factor(i);
    }
    while(cin >> n){
        printf("%d\n", memorize[n]);
    }
    
}
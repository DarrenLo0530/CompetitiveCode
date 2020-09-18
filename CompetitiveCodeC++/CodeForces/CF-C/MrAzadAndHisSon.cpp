#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pows[40];

bool isPrime(ll n){
    for(ll i = 2; i*i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}


int main(){
    pows[0] = 1;
    for(int i = 1; i<=32; i++){
        pows[i] = pows[i-1] * 2;
    }

    while(true){
        ll n;
        scanf("%lld", &n);
        if(n == 0){
            break;
        }

        ll test = pows[n-1]*(pows[n]-1);

        bool prime = isPrime(n), perfect = isPrime(pows[n] - 1);
        if(perfect){
            printf("Perfect: %lld!\n", test);
        } else if (prime) {
            printf("Given number is prime. But, NO perfect number is available.\n");
        } else {
            printf("Given number is NOT prime! NO perfect number is available.\n");
        }
    }
}
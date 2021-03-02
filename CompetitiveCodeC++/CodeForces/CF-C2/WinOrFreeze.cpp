#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isPrime[3164000];
ll factorCount(ll n){
    ll c = n;
    memset(isPrime, true, sizeof(isPrime));
    int primeCnt = 0;
    ll ans = 1;
    for(ll i = 2; i*i<=c; i++){
        if(isPrime[i]){
            //Find all prime divisors of the number 
            //(All prime divisors (except one) will be less than sqrt of the number,
            //so you just mark all numbers up until SQRT as false. You don't care if a number larger than sqrt of num is prime or not)
            for(ll j = i*i; j<=sqrt(c); j += i){
                isPrime[j] = false;
            }
            while(c % i == 0){
                c/=i;
                primeCnt++;
                if(primeCnt > 2){
                    return ans;
                }
                ans *= i;
            }
        }
    }   
    if(c != 1){
        primeCnt++;
        if(primeCnt > 2){
            return ans;
        }
        ans *= c;
    }
 
    if(primeCnt == 2){
        return -1;
    } else {
        if(primeCnt < 2){
            return 0;
        } else {
            return ans;
        }
    }
}
int main(){
    //If factor of more than two primes,
    ll q;
    cin>>q;
    ll ans = factorCount(q);
    if(ans == -1){
        cout<<2<<'\n';
    } else {
        cout<<1<<'\n';
        cout<<ans<<'\n';
    }
}

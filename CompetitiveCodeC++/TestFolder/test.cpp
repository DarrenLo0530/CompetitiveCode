#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the primeCount function below.
 */
int primeCount(long long n) {
    vector<long long> primes;
    long long product = 1LL;
    for(long long i = 2; i<=n; i++){
        bool isPrime = true;
        for(long long x: primes){
            if(i % x == 0){
                isPrime = false;
                break;
            }
        }

        if(isPrime){
            primes.push_back(i);
            product *= i;
            cout<<i<<'\n';

            if(product > n){
                cout<<product;
                return (primes.size() - 1);
            } else if (i == n){
                return primes.size();
            }
        }
    }

    return primes.size();

}

int main()
{
    long long n;
    cin>>n;

    cout<<primeCount(n);
}

#include <bits/stdc++.h>
using namespace std;

bool ask[1010];
set<int> primes;

bool isPrime(int n){
    if(primes.count(n)){
        return true;
    }

    if(n == 1){
        return false;
    }

    for(int i = 2; i<=sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }

    primes.insert(n);
    return true;
}
int main(){
    int n;
    scanf("%d", &n);
    vector<int> ans;

    for(int i = 2; i<=n; i++){
        if(isPrime(i)){
            for(int j =  i; j <= n; j *= i){
                ans.push_back(j);
            }
        }
    }

    cout<<ans.size()<<"\n";
    for(int i = 0; i<ans.size(); i++){
        if(i != 0){
            cout<<" ";
        }
        cout<<ans[i];
    }
}
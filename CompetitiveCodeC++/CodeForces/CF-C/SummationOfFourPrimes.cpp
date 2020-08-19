#include <bits/stdc++.h>
using namespace std;

bool isPrime[10000001];

pair<int, int> sumOfPrimes(int n){
    for(int i = 2; i<=(n+1)/2; i++){
        if(isPrime[i] && isPrime[n-i]){
            return make_pair(i, n-i);
        }
    }

    return {-1, -1};
}

int main(){
    memset(isPrime, true, sizeof(isPrime));

    for(int i = 2; i<=sqrt(10000000) + 1; i++){
        int counter = i;
        while(counter * i < 10000001){
            isPrime[counter*i] = false;
            counter++;
        }
    }
    
    int n;
    while(cin >> n){
        if(n < 8){
            cout<<"Impossible."<<'\n';
            continue;
        }

        if(n % 2 == 0){
            cout<<"2 2 ";
            n-=4;
        } else {
            cout<<"3 2 ";
            n-=5;
        }

        auto ans = sumOfPrimes(n);
        printf("%d %d\n", ans.first, ans.second);
    }
}
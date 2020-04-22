#include <bits/stdc++.h>
using namespace std;
const int mx = 1000001;
bool isPrime[mx] = {false};
int primeFactors[mx] = {0};


int legendres(int p, int num){
    int ans = 0;
    while(num!= 0){
        num = num/p;
        ans += num;
    }

    return ans;
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);


    for(int i = 2; i<sqrt(a) +1; i++){
        while(a%i == 0){    
            primeFactors[i]++;
            a = a/i;
        }
    }

    
    if(a != 1){
        primeFactors[a]++;
    }

    int ans = mx;
    for(int i = 0; i<mx; i++){
        if(primeFactors[i] != 0){
            ans = min(ans, legendres(i, b)/primeFactors[i]);
        }
    }

    cout<<ans;

    
}
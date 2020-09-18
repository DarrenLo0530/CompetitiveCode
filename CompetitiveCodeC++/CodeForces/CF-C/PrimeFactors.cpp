#include <bits/stdc++.h>
using namespace std;
const int MAX = 2<<16;
bool prime[MAX + 1];
vector<int> primes;

void generatePrimes(){
    memset(prime, true, sizeof(prime));

    for(int i = 2; i*i<=MAX; i++){
        for(int j = i*i; j<=MAX; j+=i){
            prime[j] = false;
        }
    }

    for(int i = 2; i<=MAX; i++){
        if(prime[i]){
            primes.push_back(i);
        }
    }
}

void printPrimes(int n){
    vector<int> nums;
    int tn = n;
    if(tn == 1){
        nums.push_back(1);
    } else {
        if(tn < 0){
            nums.push_back(-1);
            tn *= -1;
        }

        for(int i: primes){
            while(tn % i == 0){
                nums.push_back(i);
                tn/=i;
            }
        }

        if(tn != 1){
            nums.push_back(tn);
        }
    }

    printf("%d = ", n);

    for(int i = 0; i<nums.size(); i++){
        if(i != 0){
            printf(" x ");
        }
        printf("%d", nums[i]);
    }
    printf("\n");
    
}
int main(){
    generatePrimes();

    while(true){
        int n;
        scanf("%d", &n);
        if(n == 0){
            break;
        }
        printPrimes(n);
    }
}
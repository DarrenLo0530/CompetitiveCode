#include <bits/stdc++.h>
using namespace std;
bool isPrime[20000001];
pair<int, int> tp[200001];

int main(){
    memset(isPrime, true, sizeof(isPrime));

    for(int i = 2; i<= sqrt(20000000) + 1; i++){
        if(isPrime[i]){
            int counter = i;
            while(counter * i < 20000001){
                isPrime[counter * i] = false;
                counter++;
            }
        }
    }

    int cnt = 1;
    for(int i = 2; i<=20000000-2; i++){
        if(isPrime[i] && isPrime[i+2]){
            tp[cnt] = {i, i+2};
            cnt++;
        }
    }

    

    int n;
    while(cin >> n){
        printf("(%d, %d)\n", tp[n].first, tp[n].second);
    }
}
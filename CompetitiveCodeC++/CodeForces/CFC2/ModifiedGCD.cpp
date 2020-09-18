#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, n;
    scanf("%d%d%d", &a, &b, &n);
    set<int> factors;
    if(a > b){
        swap(a, b);
    }
    for(int i = 1; i*i <= a; i++){
        if(a % i == 0 && b % i == 0){
            factors.insert(i);
        }

        if(a % (a/i) == 0 && b % (a/i) == 0){
            factors.insert(a/i);
        }
    }
    while(n--){
        int low, high;
        scanf("%d%d", &low, &high);
        auto ans = --factors.upper_bound(high);
        if(*ans < low){
            cout<<-1<<"\n";
        } else {
            cout<<*ans<<"\n";
        }
        
    }
}
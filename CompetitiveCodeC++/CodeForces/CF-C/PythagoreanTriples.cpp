#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
    ll num;
    scanf("%lld", &num);
    if(num == 1 || num == 0 || num == 2){
        cout<<-1<<'\n';
        return 0;
    }

    if(num % 2 == 0){
        num /= 2;
        ll m = num;
        ll n = 1;

        ll b = m*m - n*n;
        ll a = n*n + m*m;
        cout<<a<<" "<<b<<'\n';

    } else {
        ll n = num/2;
        ll m = num - n;
        ll b = 2*m*n;
        ll a = n*n + m*m;
        cout<<b<<" "<<a<<'\n';
    }

    
}
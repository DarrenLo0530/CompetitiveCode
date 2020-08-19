#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans[50001];

int main(){
    int x;
    for(ll i = 1; i<= 50000; i++){
        ans[i] = ans[i-1];
        ans[i] += i * i * i;
    }
    while(cin >> x){
        cout<<ans[x]<<'\n';
    }
}
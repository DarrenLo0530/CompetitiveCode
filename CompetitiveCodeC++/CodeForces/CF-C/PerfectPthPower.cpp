#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, int> ans;
void generate(){
    for(int j = -(1<<16); j<=1<<16; j++){
        if(j == 0 || j == 1 || j == -1){
            continue;
        }

        int pow = 1;
        ll n = j;
        while(n >= -(1LL<<31) && n <= 1LL<<31){
            if(ans.find(n) == ans.end()){
                ans[n] = 0;
            }

            ans[n] = max(ans[n], pow);
            n *= j;
            pow++;
        }
    }
}

int main(){
    generate();
    while(true){
        ll n;
        scanf("%lld", &n);
        if(n == 0){
            break;
        }
        if(ans.find(n) != ans.end()){
            cout<<ans[n]<<'\n';
        } else {
            cout<<1<<"\n";
        }
    }
}
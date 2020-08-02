#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int bar[101];
vector<int> locationsOfNut;

int n;

int main(){
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        scanf("%d", bar+i);
        if(bar[i] == 1){
            locationsOfNut.push_back(i);
        }
    }

    ll ans = 1;

    for(int i = 1; i<locationsOfNut.size(); i++){
        ans *= locationsOfNut[i] - locationsOfNut[i-1];
    }
    if(locationsOfNut.size() == 0){
        ans = 0;
    }

    printf("%lld\n", ans);
}

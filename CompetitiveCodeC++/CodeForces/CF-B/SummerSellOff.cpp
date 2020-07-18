#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, f;
    scanf("%d%d", &n, &f);
    vector<ll> extraSold;

    ll totalSold = 0;

    for(int i = 0; i<n; i++){
        ll k, l;
        scanf("%lld%lld", &k, &l);
        if(k >= l){
            totalSold += l;
        } else {
            totalSold += k;
            l -= k;
            extraSold.push_back(min(l, k));
        }
    }

    sort(extraSold.begin(), extraSold.end());
    reverse(extraSold.begin(), extraSold.end());

    for(int i = 0; i<f && i <extraSold.size(); i++){
        totalSold += extraSold[i];
    }

    printf("%lld\n", totalSold);
}
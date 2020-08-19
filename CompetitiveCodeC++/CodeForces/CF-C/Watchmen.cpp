#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    scanf("%d", &n);

    vector<pair<int, int>> dup;
    vector<int> x, y;
    for(int i = 0; i<n; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        x.push_back(a);
        y.push_back(b);
        dup.push_back({a, b});

    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(dup.begin(), dup.end());

    ll counterX = 0, counterY = 0, sameCounter = 0;
    ll ans = 0;

    for(int i = 1; i<x.size(); i++){
        if(x[i] == x[i-1]){
            counterX++;
        } else {
            ans += counterX * (counterX + 1)/2;
            counterX = 0;
        }

        if(y[i] == y[i-1]){
            counterY++;
        } else {
            ans += counterY * (counterY + 1)/2;
            counterY = 0;
        }

        if(dup[i].first == dup[i-1].first && dup[i].second == dup[i-1].second){
            sameCounter++;
        } else {
            ans -= sameCounter * (sameCounter + 1)/2;
            sameCounter = 0;
        }
    }


    ans += counterX * (counterX + 1)/2;
    ans += counterY * (counterY + 1)/2;
    ans -= sameCounter * (sameCounter + 1)/2;


    cout<<ans<<'\n';
}
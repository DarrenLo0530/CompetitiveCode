#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n, r, avg;
    scanf("%lld%lld%lld", &n, &r, &avg);

    ll reqSum = avg*n;
    vector<pair<ll, ll>> tests;
    ll currScore = 0;
    while(n--){
        ll a, b;
        scanf("%lld%lld", &a, &b);
        currScore += a;
        tests.push_back({b, a});
    }

    if(currScore >= reqSum){
        cout<<"0";
        return 0;
    }

    ll ans = 0;
    sort(tests.begin(), tests.end());
    for(int i = 0; i<tests.size(); i++){
        auto currTest = tests[i];
        if(currTest.second >= r){
            continue;
        }

        if(r - currTest.second < reqSum - currScore){
            ans += currTest.first* (r-currTest.second);
            currScore += r-currTest.second;

        } else {
            ans+=currTest.first*(reqSum - currScore);
            break;
        }
    }

    cout<<ans;
}
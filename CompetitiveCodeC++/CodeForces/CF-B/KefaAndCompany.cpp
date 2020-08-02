#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define NINF -0x3f3f3f3f

ll psa[100005];
typedef pair<int, int> pii;

int main(){
    int n, d;
    scanf("%d%d", &n, &d);
    vector<pii> friends;
    for(int i = 0; i<n; i++){
        int m, s;
        scanf("%d%d", &m, &s);
        friends.push_back({m, s});
    }

    sort(friends.begin(), friends.end());
    for(int i = 1; i<=friends.size(); i++){
        psa[i] = psa[i-1] + friends[i-1].second;
    }

    ll ans = 0;
    for(int i = 0; i<friends.size(); i++){
        int richest = lower_bound(friends.begin(), friends.end(), make_pair(friends[i].first + d, NINF)) - friends.begin();
        ans = max(ans, psa[richest] - psa[i]);
    }

    cout<<ans;  
    
}
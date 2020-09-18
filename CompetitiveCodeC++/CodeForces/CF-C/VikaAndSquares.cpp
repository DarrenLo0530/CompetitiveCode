#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int buckets[200001];
int main(){
    int n;

    set<int> pos;
    scanf("%d", &n);
    int lowest = 0x3f3f3f3f;
    for(int i = 1; i<=n; i++){
        int a;
        scanf("%d", &a);
        lowest = min(a, lowest);
        buckets[i] = a;
    }

    ll ans = 0;
    for(int i = 1; i<=n; i++){
        if(buckets[i] == lowest){
            pos.insert(i);
            pos.insert(i + n);
        }
    }

    for(int i = 1; i<=n; i++){
        auto nextBucket = pos.lower_bound(i);
        ans = max(ans, (ll)n*(lowest) + *nextBucket - i);
    }


    cout<<ans<<"\n";
}
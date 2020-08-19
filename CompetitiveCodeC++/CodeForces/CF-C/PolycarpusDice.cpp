#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dice[200010];
int ans[200010];
int main(){
    ll n, a;
    scanf("%lld%lld", &n, &a);
    ll totalSum = 0;
    for(int i = 0; i<n; i++){
        scanf("%lld", dice+i);
        totalSum += dice[i];
    }

    for(int i = 0; i<n; i++){
        ll first = max(0LL, dice[i] - (a - (n-1)));
        ll second = max(0LL, a - (totalSum - dice[i]) - 1);
        ans[i] = first + second;
    }

    for(int i = 0; i<n; i++){
        if(i != 0){
            cout<<" ";
        }
        cout<<ans[i];
    }
    cout<<"\n";
}
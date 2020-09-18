#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100011];
int main(){
    ll ans = 0;
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d", a + i);
    }

    a[n] = 0x3f3f3f3f;

    for(int start = 0; start <=n; start++){
        int end = start;
        while(a[end + 1] == a[start]){
            end++;
        }
        //1 2 3
        ll num = end-start + 1;
        ans += num*(num+1)/2;
        start = end;
    }

    ans--;
    cout<<ans<<'\n';

}
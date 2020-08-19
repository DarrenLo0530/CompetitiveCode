#include <bits/stdc++.h>
using namespace std;
int pre[1000010];
int main(){
    int n;
    scanf("%d", &n);

    for(int i = 1; i<=n; i++){
        pre[i] = i ^ pre[i-1];
    }

    int ans = 0;
    for(int i = 1; i<=n; i++){
        int p;
        scanf("%d", &p);

        if((n/i) % 2 == 0){
            ans ^= p ^ pre[n % i];
        } else {
            ans ^= p ^ pre[i - 1] ^ pre[n % i];
        }
    }

    cout<<ans<<'\n';


}
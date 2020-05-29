#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    while(true){
        int n;
        scanf("%d", &n);

        if(n == 0){
            break;
        }

        ll ans = 0;
        ll prev = 0;
        
        for(int i = 0; i<n; i++){
            int x;
            scanf("%d", &x);

            ans += abs(prev);
            prev += x;
        }

        cout << ans << '\n';
    }
}
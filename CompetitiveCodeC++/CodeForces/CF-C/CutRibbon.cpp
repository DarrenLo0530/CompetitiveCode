#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b, c;
    scanf("%d%d%d%d", &n, &a, &b, &c);

    int ans = 0;
    for(int i = 0; i*a<=n; i++){
        for(int j = 0; j*b <= n; j++){
            int remLen = n - i*a - j*b;
            if(remLen < 0 || !(remLen % c == 0)){
                continue;
            } 

            ans = max(ans, i + j + remLen/c);
        }
    }

    cout<<ans<<'\n';
}
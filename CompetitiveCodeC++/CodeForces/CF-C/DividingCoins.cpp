#include <bits/stdc++.h>
using namespace std;

bool coins[50050];

int main(){
    int t;
    scanf("%d", &t);
    
    while(t--){
        memset(coins, false, sizeof(coins));
        coins[0] = true;

        int m;
        scanf("%d", &m);

        int total = 0;
        for(int i =0; i<m; i++){
            int x;
            scanf("%d", &x);
            total += x;

            for(int i = 50000; i>=0; i--){
                if(coins[i] && i + x <= 50000){
                    coins[i + x] = true;
                }
            }
        }


        for(int i = total/2; i>=0; i--){
            if(coins[i]){
                int ans = abs(i - (total - i));
                cout<<ans<<'\n';
                break;
            }
        }
    }
}
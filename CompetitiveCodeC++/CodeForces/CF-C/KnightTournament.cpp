#include <bits/stdc++.h>
using namespace std;
int ans[300005];
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    set<int> alive;

    for(int i = 1; i<=n; i++){
        alive.insert(i);
    }
    for(int i = 0; i<m; i++){
        int l, r, x;

        scanf("%d%d%d", &l, &r, &x);
        auto left = alive.lower_bound(l);
        for(auto idx = left; idx != alive.upper_bound(r);){
            if (*idx == x){
                ++idx;
                continue;
            }
            
            ans[*idx] = x;
            idx = alive.erase(idx++);
        }

    }

    for(int i = 1; i<=n; i++){
        if(i != 1){
            cout<<" ";
        }   

        cout<<ans[i];
    }
}
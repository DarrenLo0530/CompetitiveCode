#include <bits/stdc++.h>
using namespace std;
int psa[100001];
set<int> locations[3001];

int main(){
    int n, k, q;
    scanf("%d%d%d", &n, &k, &q);

    for(int i = 1; i<=n; i++){
        int x;
        scanf("%d", &x);
        locations[x+1000].insert(i);   
        psa[i] = x + psa[i-1];
    }

    while(q--){
        int a, b, x, y;
        scanf("%d%d%d%d", &a, &b, &x, &y);

        if(psa[y] - psa[x-1] <= k){
            cout << "No" << '\n';
        } else {
            //Finds next largest in range
            auto aInRange = locations[a+1000].lower_bound(x);
            auto bInRange = locations[b+1000].lower_bound(x);

            if(*aInRange <= y && *aInRange >= x && *bInRange <= y && *bInRange >= x){
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
            }
        }
    }

}

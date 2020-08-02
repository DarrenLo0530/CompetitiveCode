#include <bits/stdc++.h>
using namespace std;
bitset<1001> a;
bitset<1001> ans;

int main(){
    int n;
    scanf("%d", &n);


    for(int j = 0; j<n; j++){
        for(int i = 0; i<3; i++){
            int x;
            scanf("%d", &x);

            if(x & a[j]){
                ans.set(j);
            }

            a[j] = a[j] | x;
        }
    }
    

    printf("%d", ans.count());
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int last = 0x3f3f3f3f;
    vector<pair<int, int>> subs;
    for(int i = 0; i<m; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        last = min(last, r-l+1);
    }  

    cout<<last<<'\n';
    for(int i = 0; i<n; i++){
        if(i != 0){
            cout<<" ";
        }

        cout<<i%last;
    }
    
}
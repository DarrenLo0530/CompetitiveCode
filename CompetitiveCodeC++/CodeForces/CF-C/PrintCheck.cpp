#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
pii rows[5001];
pii cols[5001];

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i =1;i<=k; i++){
        int o, p, a;
        
        scanf("%d%d%d", &o, &p, &a);
        p--;

        if(o == 1){
            rows[p] = {a, i};
        } else {
            cols[p] = {a, i};
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(j != 0){
                cout<<" ";
            }

            if(rows[i].second == cols[j].second){
                cout<<0;
            } else if(rows[i].second > cols[j].second){
                cout<<rows[i].first;
            } else {
                cout<<cols[j].first;
            }
        }

        cout<<"\n";
    }
}
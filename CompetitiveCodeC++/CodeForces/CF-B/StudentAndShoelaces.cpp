#include <bits/stdc++.h>
using namespace std;

set<int> laces[101];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 0; i<m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        laces[a].insert(b);
        laces[b].insert(a);
    }

    int ans = 0;
    vector<int> kickedOut;
    
    while(true){
        kickedOut.clear();

        for(int i = 1; i<=n; i++){
            if(laces[i].size() == 1){
                kickedOut.push_back(i);
            }
        }

        if(!kickedOut.size()){
            break;
        }

        for(int i: kickedOut){
            laces[i].clear();
            for(int j = 1; j<=n; j++){
                laces[j].erase(i);
            }
        }

        ans++;
    }

    printf("%d", ans);
}
#include <bits/stdc++.h>
using namespace std;
int n, k;

bool adj[101][101];
bool black[101];
bool ans[101];
int maxNum;

bool canColour(int x){
    for(int i = 1; i<=n; i++){
        if(black[i] && adj[x][i]){
            return false;
        }
    }
    return true;
}

void dfs(int curr){
    if(curr > n){  
        int cnt = 0;
        for(int i = 1; i<=n; i++){
            if(black[i]){
                cnt++;
            }
        }  

        if(cnt > maxNum){
            maxNum = cnt;
            for(int i = 1; i<=n; i++){
                ans[i] = black[i];
            }
        }
        
        return;
    }


    if(canColour(curr) && !black[curr]){
        black[curr] = true;
        dfs(curr + 1);
        black[curr] = false;
    }
    
    dfs(curr + 1);
}
int main(){
    int m;
    scanf("%d", &m);

    while(m--){
        memset(adj, false, sizeof(adj));
        memset(black, false, sizeof(black));
        memset(ans, false, sizeof(ans));
        maxNum = 0;

        scanf("%d%d", &n, &k);

        for(int j = 0; j<k; j++){
            int s, e;
            scanf("%d%d", &s, &e);
            adj[s][e] = adj[e][s] = true;
        }

        dfs(0);

        cout<<maxNum<<'\n';
        bool first = true;
        for(int i = 1; i<=n; i++){
            if(ans[i]){
                if(!first){
                    cout<<" ";
                } else {
                    first = false;
                }

                cout<<i;
            }
        }
        cout<<'\n';     

    
    }
}
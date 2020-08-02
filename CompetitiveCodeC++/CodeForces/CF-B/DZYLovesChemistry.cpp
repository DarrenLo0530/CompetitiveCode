#include <bits/stdc++.h>
using namespace std;

bool visited[51];
vector<int> adj[51];
bool reacts[51];

void dfs(int curr){
    visited[curr] = true;
    for(int i: adj[curr]){
        if(!visited[i]){
            dfs(i);
        }

    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 0; i<m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
        reacts[x] = true;
        reacts[y] = true;
    }

    int numReacts = 0;
    for(int i = 1; i<=n; i++){
        if(reacts[i]){
            numReacts++;
        }
    }

    if(numReacts == 0){
        printf("1\n");
    } else {
        
        for(int i = 1; i<=n; i++){
            if(!visited[i] && reacts[i]){
                numReacts--;
                dfs(i);
            }
        }

        long long ans = pow(2, numReacts);
        printf("%lld\n", ans);
    }

}
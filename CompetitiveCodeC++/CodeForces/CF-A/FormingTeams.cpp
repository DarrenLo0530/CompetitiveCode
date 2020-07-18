#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
bool v[101];

int dfs(int curr, int par, int count){
    if(v[curr]){
        return count;
    }

    v[curr] = true;
    count++;

    for(int i: adj[curr]){
        if(i == par){
            continue;
        }

        int cycleCount = dfs(i, curr, count);

        if(cycleCount != -1){
            return cycleCount;
        }
    }

    return -1;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int exclude = 0;

    for(int i = 1; i<=n; i++){
        if(!v[i]){
            int count = dfs(i, -1, 0);
            if(count != -1 && count % 2 != 0){
                ++exclude;
            }
        }
    }

    if((n-exclude) % 2 != 0){
        ++exclude;
    }

    printf("%d\n", exclude);
}
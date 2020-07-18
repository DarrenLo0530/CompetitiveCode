#include <bits/stdc++.h>
using namespace std;

stack<int> ans;
bool visited[101];

void tSort(int curr, set<int> adj[]){
    for(int i: adj[curr]){
        if(!visited[i]){
            tSort(i, adj);
        }
    }

    visited[curr] = true;
    ans.push(curr);
}


int main(){
    while(true){
        memset(visited, false, sizeof(visited));
        set<int> adj[101];

        int n, m;
        scanf("%d%d", &n, &m);
        if(n == 0 && m ==0){
            break;
        }

        while(m--){
            int i, j;

            scanf("%d%d", &i, &j);
            adj[i].insert(j);
        }

        for(int i = 1; i<=n; i++){
            if(!visited[i]){
                tSort(i, adj);
            }
        }

        while(!ans.empty()){
            cout << ans.top();
            ans.pop();
            if(!ans.empty()){
                cout << " ";
            }
        }
        cout << '\n';
    }
}

#include <bits/stdc++.h>
using namespace std;
int rnk[501];
vector<int> adj[501];
vector<int> ans;
bool visiting[501], visited[501];
int n;

bool topSort(int curr){
    visiting[curr] = true;
    for(int i: adj[curr]){
        if(visiting[i]){
            return false;
        }

        if(visited[i]){
            continue;
        }

        if(!topSort(i)){
            return false;
        }
    }
    visiting[curr] = false;
    visited[curr] = true;

    ans.push_back(curr);
    return true;
}
bool topSortUtil(){
    for(int i = 1; i<=n; i++){
        if(!visited[i]){
            if(!topSort(i)){
                return false;
            }
        }
    }

    return true;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);

        for(int i = 0; i<501; i++){
            ans.clear();
            visiting[i] = false;
            visited[i] = false;
            rnk[i] = 0;
            adj[i].clear();
        }

        for(int i = 1; i<=n; i++){
            scanf("%d", rnk + i);
        }

        

        set<pair<int, int>> changes;
        int m;
        scanf("%d", &m);
        for(int i =0;i <m; i++){
            int a, b;
            scanf("%d%d",&a, &b);
            changes.insert({a, b});
            changes.insert({b, a});
        }

        for(int i = 1; i<=n; i++){
            for(int j = i+1; j<=n; j++){
                if(changes.count({rnk[i], rnk[j]})){
                    adj[rnk[j]].push_back(rnk[i]);
                } else {
                    adj[rnk[i]].push_back(rnk[j]);
                }
            }
        }

        if(topSortUtil()){
            for(int i = ans.size()-1; i>=0; i--){
                if(i != ans.size() - 1){
                    cout<<" ";
                }
                cout<<ans[i];
            }

            cout<<'\n';
        } else {
            printf("IMPOSSIBLE\n");
        }

        
    }

}
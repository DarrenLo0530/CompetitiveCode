#include <bits/stdc++.h>
using namespace std;
#define mx 100001

set<int> incoming[mx];
set<int> outgoing[mx];

int longestPath[mx];

//Other way of doing it:
//Find nodes that have no incoming
//DFS to find furthest node and the ans is the max of ans and that dist
//Marks curr node as visited since the max dist from currnode to another node is constant
int main(){
    int N, M, x, y;
    
    cin >> N >> M;
    for(int i = 0; i<M; i++){
        scanf("%d %d", &x, &y);
        outgoing[x].insert(y);
        incoming[y].insert(x);
    }  
    
    while(true){
        bool remaining = false;

        for(int i = 1; i<=N; i++){
            if(incoming[i].size() == 0 && outgoing[i].size() != 0){
                remaining = true;
                for(int d: outgoing[i]){
                    longestPath[d] = max(longestPath[d], longestPath[i] + 1);
                    incoming[d].erase(i);
                }
                outgoing[i].clear();
            }
        }

        if(!remaining){
            break;
        }
    }

    int ans = 0;
    for(int i = 1; i<=N; i++){
        ans = max(ans, longestPath[i]);
    }

    cout<<ans<<'\n';


}
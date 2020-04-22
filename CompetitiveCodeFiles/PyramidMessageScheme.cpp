#include <bits/stdc++.h>

using namespace std;

struct node{
    int d, w;
};

int main(){
    int N, L;

    scanf("%d", &L);
    for(int i = 0; i<L; i++){
        vector<string> index;
        string home;
        scanf("%d", &N);
        string order[N];

        for(int i = 0; i<N; i++){
            cin>>order[i];
            if(!count(index.begin(), index.end(), order[i])){
                index.push_back(order[i]);
            }
        }

        bool foundHome = false;
        for(int i = 1; i<N; i++){
            if(order[i] == order[0]){
                home = order[i+1];      
                foundHome = true;
            }
        }
        if(!foundHome){
            home = order[1];
        }

        vector<int> adj[index.size()+1];

        int ans;

        for(int i = 0; i<N; i++){
            vector<string>::iterator it1, it2;
            if(i == 0){
                it1 = find(index.begin(), index.end(), home);
                it2 = find(index.begin(), index.end(), order[i]);

            } else {
                it1 = find(index.begin(), index.end(), order[i-1]);
                it2 = find(index.begin(), index.end(), order[i]);
            }
            int ind1 = distance(index.begin(), it1);
            int ind2 = distance(index.begin(), it2);
            adj[ind1].push_back(ind2);
        }

        int rootNode = distance(index.begin(), find(index.begin(), index.end(), home));
        int maxLen = 0;
        stack<node> toVisit;
        bool visited[index.size()] = {false};
        toVisit.push(node{rootNode, 0});
        visited[rootNode] = true;

        while(!toVisit.empty()){
            node curr = toVisit.top();
            toVisit.pop();
            maxLen = max(maxLen, curr.w);

            for(int i: adj[curr.d]){
                if(!visited[i]){
                    toVisit.push(node{i, curr.w+1});
                    visited[i] = true;
                }
            }
        }
        ans = 20*(index.size()-1) - maxLen*20;
        cout<<ans<<"\n";


    }
}
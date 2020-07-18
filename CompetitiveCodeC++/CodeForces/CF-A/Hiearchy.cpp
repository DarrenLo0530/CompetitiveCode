#include <bits/stdc++.h>
using namespace std;

vector<int> wishes[100001];
bool visited[100001];
int bosses[100001];

stack<int> ans;

void tSort(int curr){
    //Ensures all children are listed before current node
    for(int i: wishes[curr]){
        //Child is already listed before
        if(!visited[i]){
            tSort(i);
        }
    }

    visited[curr] = true;    
    ans.push(curr);
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i<=k; i++){
        int w;
        scanf("%d", &w);

        while(w--){
            int cw;
            scanf("%d", &cw);
            wishes[i].push_back(cw);
        }
    }

    for(int i = 1; i<=n; i++){
        if(!visited[i]){
            tSort(i);
        }
    }

    int prev = ans.top();
    ans.pop();
    bosses[prev] = 0;

    while(!ans.empty()){
        int next = ans.top();
        ans.pop();

        bosses[next] = prev;
        prev = next;
    }

    for(int i = 1; i<=n; i++){
        cout<<bosses[i]<<'\n';
    }
}
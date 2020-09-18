#include <bits/stdc++.h>
using namespace std;
int s[100001], d[100001];
vector<int> adj[100001];
vector<int> nodes;
int cnt = 0;
void dfs(int curr, int parNum, int par, int parPar){
    if(parPar){
        s[curr] = 1 - s[curr];
    }
    if(s[curr] != d[curr]){
        nodes.push_back(curr);
        cnt++;
        parPar = 1 - parPar;
    } 

    for(int i: adj[curr]){
        if(i != parNum){
            dfs(i, curr, parPar, par);
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n-1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i<=n; i++){
        scanf("%d", s + i);
    }

    for(int i = 1; i<=n; i++){
        scanf("%d", d + i);
    }
    dfs(1, -1, false, false);
    printf("%d\n", cnt);
    for(int i: nodes){
        printf("%d\n", i);
    }
}
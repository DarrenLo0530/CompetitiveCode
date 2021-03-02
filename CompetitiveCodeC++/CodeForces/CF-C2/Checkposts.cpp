//Strongly connected components problem
#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int MX = 1e5+1;
const int md = 1e9 + 7;

int c[MX];
vector<int> adj[MX];
vector<int> rev[MX];

bool visited[MX];
stack<int> nodes;

multiset<int> costs;

void firstPass(int curr){
    visited[curr] = true;
    for(int i: adj[curr]){
        if(!visited[i]){
            firstPass(i);
        }
    }
    nodes.push(curr);
}

void secondPass(int curr){
    visited[curr] = true;
    costs.insert(c[curr]);
    for(int i: rev[curr]){
        if(!visited[i]){
            secondPass(i);
        }
    }
}

 

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 1; i<=n; i++){
        scanf("%d", c + i);
    }

    int m;
    scanf("%d", &m);
    
    for(int i = 0; i<m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    for(int i = 1; i<=n; i++){
        if(!visited[i]){
            firstPass(i);
        }
    }

    memset(visited, false, sizeof(visited));

    ll cost = 0;
    ll combo = 1;
    while(!nodes.empty()){
        costs.clear();
        int next = nodes.top();
        nodes.pop();
        if(visited[next]){
            continue;
        }

        secondPass(next);
        int minCost = *costs.begin();
        int appearances = costs.count(minCost);

        cost += minCost;
        combo = (combo * appearances) % md;
    }

    cout << cost << " " << combo << '\n';

}
#include <bits/stdc++.h>

using namespace std;

int N;

const int l = 100001;
bool vis[l];
int st[20][2*l];
int indx[20][2*l];
int n[2*l];
long long dist[l];
int firstApp[l];

class Node{
    public:
        int dest;
        long long weight;

        Node(int dest, long long weight){
            this->dest = dest;
            this->weight = weight;
        }
};

vector<Node> adj[l];

void generateEt(int curr, int height, int& index){
    vis[curr] = true;
    if(firstApp[curr] == 0 && curr!=1){
        firstApp[curr] = index;
    }

    st[0][index] = height;
    n[index++] = curr;
    for (auto i : adj[curr]){ 
        if (!vis[i.dest]) { 
            generateEt(i.dest, height+1, index);
            st[0][index] = height;
            n[index++] = curr;
        } 
    } 
}

void generateSt(){
    for(int i = 0; i<N*2; i++){
        indx[0][i] = i;
    }

    for(int i = 1; i<20; i++){
        for(int j = 0; j<N*2; j++){
            if((j + (int)pow(2, i-1)) < l*2){
                if(st[i-1][j] < st[i-1][j + (int)pow(2, i-1)]){
                    indx[i][j] = indx[i-1][j];
                    st[i][j] = st[i-1][j];
                } else {
                    st[i][j] = st[i-1][j + (int)pow(2, i-1)];
                    indx[i][j] = indx[i-1][j + (int)pow(2, i-1)];                    
                }
            }
        }
    }
}

int lca(int n1, int n2){
    int n1i = firstApp[n1];
    int n2i = firstApp[n2];

    int len = abs(n2i - n1i) + 1;
    int lev = (int) log2(len);

    if(st[lev][min(n2i, n1i)] < st[lev][max(n2i, n1i) - (1 << lev) + 1]){
        return n[indx[lev][min(n2i, n1i)]];
    } else {
        return n[indx[lev][max(n2i, n1i) - (1 << lev) + 1]];
    }
}


long long sp(int n1, int n2){
    return dist[n1] + dist[n2] - dist[lca(n1, n2)]*2;
}

int main(){
    int D, a, b, c;
    scanf("%d %d", &N, &D);

    for(int i = 0; i<N-1; i++){
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back(Node(b,c));
        adj[b].push_back(Node(a,c));
    }

    bool visited[N+1] = {false};
    stack<Node> toVisit;
    toVisit.push(Node(1, 0));
    visited[1] = true;

    while(!toVisit.empty()){
        Node curr = toVisit.top();
        dist[curr.dest] = curr.weight;
        toVisit.pop();

        for(Node i: adj[curr.dest]){
            if(!visited[i.dest]){
                visited[i.dest] = true;
                toVisit.push(Node(i.dest, i.weight + curr.weight));
            }
        }
    }

    int index = 0;
    generateEt(1, 1, index);
    generateSt();
    
    int b1 = 1;
    int b2 = 1;
    int newb1, newb2;
    long long dp[2] = {0};
        
    for(int i = 0; i<D; i++){
        scanf("%d %d", &newb1, &newb2);
        long long x = sp(newb1, newb2);
        long long newVal1 = min(dp[0] + sp(b1, newb1), dp[1] + sp(b2, newb1)) + x;
        long long newVal2 = min(dp[0] + sp(b1, newb2), dp[1] + sp(b2, newb2)) + x;
        dp[1] = newVal1;
        dp[0] = newVal2;
        b1 = newb1;
        b2 = newb2;
    }

    cout<< min(dp[0], dp[1]);
}   
#include <bits/stdc++.h>
using namespace std;
static const int l = 100001;
int N, M;

bool pho[l] = {false};
bool np[l] = {false};
bool visited[l] = {false};
vector<int> adj[l];

bool removeNodes(int curr){
    bool x;
    bool isp = pho[curr];

    for(int i: adj[curr]){
        if(!visited[i]){
            visited[i] = true;
            x = removeNodes(i);
            isp = isp || x;
        }
    }

    if(!isp){
        np[curr] = true;
        N--;
    }
    return isp;
}

class Node{
    public:
        int s, w;
        Node(int s, int w){
            this->s = s;
            this->w = w;
        }
};

int main(){
    int p, f, d;
    scanf("%d %d", &N, &M);

    for(int i = 0; i<M; i++){
        scanf("%d", &p);
        pho[p] = true;
    }


    for(int i = 0; i<N-1; i++){
        scanf("%d %d", &f, &d);
        adj[f].push_back(d);
        adj[d].push_back(f);
    }

    visited[p] = true;
    removeNodes(p);

    int n1, n2;

    queue<Node> tv;
    bool bfsv1[l] = {false};
    bool bfsv2[l] = {false};
    int currm1 = -1;
    int currm2 = -1;

    bfsv1[p] = true;
    tv.push(Node(p, 0));
    while(!tv.empty()){
        Node curr = tv.front();
        tv.pop();
        if(curr.w >= currm1){
            currm1 = curr.w;
            n1 = curr.s;
        }
        for(int i: adj[curr.s]){
            if(!bfsv1[i] && !np[i]){
                bfsv1[i] = true;
                tv.push(Node(i, curr.w+1));
            }
        }
    }

    bfsv2[n1] = true;
    tv.push(Node(n1, 0));
    while(!tv.empty()){
        Node curr = tv.front();
        tv.pop();
        if(curr.w >= currm2){
            n2 = curr.s;
            currm2 = curr.w;
        }
        for(int i: adj[curr.s]){
            if(!bfsv2[i] && !np[i]){
                bfsv2[i] = true;
                tv.push(Node(i, curr.w+1));
            }
        }
    }

    printf("%d\n", (2*(N-1)-currm2));
}
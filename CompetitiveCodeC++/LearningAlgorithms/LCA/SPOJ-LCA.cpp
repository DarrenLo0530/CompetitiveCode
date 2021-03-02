#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

vector<int> adj[1001];
vector<pii> eulerTour;
int firstIndex[1001];
pii segmentTree[10000];
int n;

//Euler tour is a list that contains the order of traversal of a tree. When you visit any node, add it to the euler tour along with its depth in the tree.
void constructEulerTour(int currNode, int depth){
    if(firstIndex[currNode] == 0){
        firstIndex[currNode] = eulerTour.size()+1;
    }

    eulerTour.push_back({currNode, depth});
    for(int i: adj[currNode]){
        constructEulerTour(i, depth+1);
        eulerTour.push_back({currNode, depth});
    }
}

pii merge(pii first, pii second){
    return (first.second < second.second) ? first : second;
}


//Constructs a segment tree with range minimum query for the minimum height node in a range in a euler tour.
//The node with a minimum height is the LCA of two nodes.
void constructSegmentTree(int l, int r, int idx){
    if(l == r){
        if(l-1 >= eulerTour.size()){
            segmentTree[idx] = {INF, INF};
        } else {
            segmentTree[idx] = eulerTour[l-1];
        }

        return;
    }

    if(l > r){
        return;
    }

    int mid = (l + r)/2;
    constructSegmentTree(l, mid, idx*2);
    constructSegmentTree(mid+1, r, idx*2+1);


    segmentTree[idx] = merge(segmentTree[idx*2], segmentTree[idx*2+1]);

}

pii query(int l, int r, int ql, int qr, int idx){
    if(l > r || ql > r || qr < l){
        return {INF, INF};
    }

    if(qr >= r && ql <= l){
        return segmentTree[idx];
    }

    int mid = (l + r)/2;
    return merge(query(l, mid, ql, qr, idx*2), query(mid+1, r, ql, qr, idx*2+1));
}

int main(){
    int t;
    scanf("%d", &t);
    for(int x = 1; x<=t; x++){
        for(int i = 1; i<=1000; i++){
            adj[i].clear();
        }
        memset(firstIndex, 0, sizeof(firstIndex));
        eulerTour.clear();

        set<int> nodes;
        scanf("%d", &n);
        for(int i = 1; i<=n; i++){
            nodes.insert(i);
        }


        for(int i = 1; i<=n; i++){
            int m;
            scanf("%d", &m);
            while(m--){
                int c;
                scanf("%d", &c);
                adj[i].push_back(c);
                nodes.erase(c);
            }
        }

        int root = *nodes.begin();
        constructEulerTour(root, 0);
        constructSegmentTree(1, eulerTour.size(), 1);

        int q;
        scanf("%d", &q);

        printf("Case %d:\n", x);
        for(int i = 0; i<q; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            int l = min(firstIndex[a], firstIndex[b]);
            int r = max(firstIndex[a], firstIndex[b]);
            pii ans = query(1, eulerTour.size(), l, r, 1);
            printf("%d\n", ans.first);
        }
    
    }
    

}
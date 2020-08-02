#include <bits/stdc++.h>
using namespace std;
int n, m;
int rnk[101];
int par[101];
vector<int> bestPath;

int getPar(int n){
    if(par[n] < 0){
        return n;
    }

    par[n] = getPar(par[n]);
    return par[n];
}

int un(int n1, int n2){
    n1 = getPar(n1);
    n2 = getPar(n2);
    if(n1 == n2){
        return false;
    }

    if(rnk[n1] > rnk[n2]){
        rnk[n1]++;
        par[n2] = n1;
    } else {
        rnk[n2]++;
        par[n1] = n2;
    }
    return true;
}

struct Edge{
    int a, b, c;

    bool operator<(const Edge &e1) const {
        return c < e1.c;
    }
};

int mstsize(vector<Edge> edges, bool best){
    memset(rnk, 1, sizeof(rnk));
    memset(par, -1, sizeof(par));
    int cost = 0;

    for(int i = 0; i<edges.size(); i++){
        if(un(edges[i].a, edges[i].b)){
            cost += edges[i].c;
            if(best){
                bestPath.push_back(i);
            }
        }
    }
    
    int testPar = getPar(1);
    for(int i = 2; i<=n; i++){
        if(getPar(i) != testPar){
            return 0x3f3f3f3f;
        }
    }

    return cost;
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        bestPath.clear();
        vector<Edge> edges;
        scanf("%d%d", &n, &m);

        for(int i = 0; i<m; i++){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            edges.push_back(Edge{a, b, c});
        }

        sort(edges.begin(), edges.end());
        int shortest = mstsize(edges, true);
        int shortest2 = 0x3f3f3f3f;
        for(int i: bestPath){
            vector<Edge> dup = edges;
            dup.erase(dup.begin() + i);
            int temp = mstsize(dup, false);
            shortest2 = min(temp, shortest2);
        }

        printf("%d %d\n", shortest, shortest2);
    }

}
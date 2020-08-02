#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int start, end;
    double cost;

    bool operator<(const Edge &e1) const {
        return cost < e1.cost;
    }
};


int x[501], y[501], rnk[501], par[501];

double distance(int p1, int p2){
    return sqrt((double) pow(x[p1] - x[p2], 2) + pow(y[p1] - y[p2], 2));
}

int getPar(int n){
    if(par[n] < 0){
        return n;
    }

    par[n] = getPar(par[n]);
    return par[n];
}

int un(int p1, int p2){
    p1 = getPar(p1);
    p2 = getPar(p2);
    if(p1 == p2){
        return false;
    }

    if(rnk[p2] > rnk[p1]){
        swap(p1, p2);
    }

    rnk[p1]++;
    par[p2] = p1;
    return true;
}


int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        memset(par, -1, sizeof(par));
        memset(rnk, 1, sizeof(rnk));

        vector<Edge> edges;

        int s, p;
        scanf("%d%d", &s, &p);

        for(int i = 0; i<p; i++){
            scanf("%d%d", x+i, y+i);
        }

        for(int i = 0; i<p; i++){
            for(int j = i+1; j<p; j++){
                edges.push_back(Edge{i, j, distance(i, j)});
            }
        }

        sort(edges.begin(), edges.end());
        vector<Edge> used;

        for(Edge e: edges){
            if(un(e.start, e.end)){
                used.push_back(e);
            }
        }

        s--;
        int index = used.size() - 1 - s;
        if(index < 0){
            printf("%.2f\n", 0);
        } else {
            printf("%.2f\n", used[index].cost);
        }

        
    }
}
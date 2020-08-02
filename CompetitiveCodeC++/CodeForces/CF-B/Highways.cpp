#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct Highway{
    double dist;
    int s, e;

    bool operator < (const Highway &h1) const {
        return dist < h1.dist;
    }
};

pii town[751];
int parent[751];
int rnk[751];
set<pii> used;
vector<Highway> newh;

double calculateDist(int t1, int t2){
    return sqrt((double) pow(town[t1].first - town[t2].first, 2) + pow(town[t1].second - town[t2].second, 2));
}

int getPar(int n){
    if(parent[n] < 0){
        return n;
    }

    parent[n] = getPar(parent[n]);
    return parent[n];
}

bool un(int s, int e){
    int par1 = getPar(s);
    int par2 = getPar(e);
    if(par1 == par2){
        return false;
    }

    if(rnk[par1] > rnk[par2]){
        rnk[par1] += rnk[par2];
        parent[par2] = par1;
    } else {
        rnk[par2] += rnk[par1];
        parent[par1] = par2;
    }

    return true;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int c = 0; c<t; c++){
        if(c != 0){
            cout<<'\n';
        }

        used.clear();
        newh.clear();
        memset(parent, -1, sizeof(parent));
        memset(rnk, 1, sizeof(rnk));

        int n;
        scanf("%d", &n);

        for(int i = 1; i<=n; i++){
            int x, y;
            scanf("%d%d", &x, &y);
            town[i] = {x, y};
        }


        int m;
        scanf("%d", &m);

        while(m--){
            int s, e;
            scanf("%d%d", &s, &e);
            used.insert({s, e});
            used.insert({e, s});
            un(s, e);
        }

        for(int i = 1; i<=n; i++){
            for(int j = i+1; j<=n; j++){
                if(!used.count({i, j} )){
                    newh.push_back({calculateDist(i, j), i, j});
                }
            }
        }

        sort(newh.begin(), newh.end());
        vector<pii> ans;
        for(auto i: newh){
            if(un(i.s, i.e)){
                ans.push_back({i.s, i.e});
            }
        }
        
        if(ans.size() == 0){
            printf("No new highways need\n");
        } else {
            for(auto i: ans){
                printf("%d %d\n", i.first, i.second);
            }
        }
    }
}
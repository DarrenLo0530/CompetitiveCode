#include <bits/stdc++.h>
using namespace std;

struct Edge{
    string a, b;
    int c;

    bool operator < (Edge e1){
        return c < e1.c;
    }
};

map<string, pair<string, int>> ds;

string getPar(string c){
    if(ds[c].first == ""){
        return c;
    }

    ds[c].first = getPar(ds[c].first);
    return ds[c].first;
}

bool un(string c1, string c2){
    string p1 = getPar(c1);
    string p2 = getPar(c2);

    if(p1 == p2){
        return false;
    }

    if(ds[p1].second > ds[p2].second){
        ds[p2].first = p1;
        ds[p1].second += ds[p2].second;
    } else {
        ds[p1].first = p2;
        ds[p2].second += ds[p1].second;
    }

    return true;
}
int main(){
    int t;
    scanf("%d", &t);


    for(int x = 0; x<t; x++){
        if(x!=0){
            cout<<'\n';
        }
        
        ds.clear();
        vector<Edge> edges;

        int m, n;
        scanf("%d%d", &m, &n);
        int minCost = 0;
        while(n--){
            string a, b;
            int c;
            cin >> a >> b >> c;
            edges.push_back(Edge{a, b, c});

            ds[a] = {"", 1};
            ds[b] = {"", 1};
        }

        sort(edges.begin(), edges.end());

        for(auto i: edges){
            if(un(i.a, i.b)){
                minCost += i.c;
            }
        }

        cout<<minCost<<'\n';


    }
}
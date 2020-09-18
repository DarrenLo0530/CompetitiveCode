#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int rnk[101], ds[101];
int getPar(int curr){
    if(!ds[curr]){
        return curr;
    }
    return ds[curr] = getPar(ds[curr]);
}

bool un(int a, int b){
    a = getPar(a);
    b = getPar(b);
    if(a == b){
        return false;
    }
    if(rnk[a] < rnk[b]){
        swap(a, b);
    }

    rnk[a]++;
    ds[b] = a;
    return true;
}

vector<int> solve(vector<pair<int, pii>> edges, int ex){
    memset(rnk, 0, sizeof(rnk));
    memset(ds, 0, sizeof(ds));
    vector<int> ret;
    for(int i = 0; i<edges.size(); i++){
        if(i == ex){
            continue;
        }
        if(un(edges[i].second.first, edges[i].second.second)){
            ret.push_back(i);
        }
    }
    return ret;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int c = 1; c<=t; c++){
        vector<pair<int, pii>> edges;
        printf("Case #%d : ", c);
        int v, e;
        scanf("%d%d", &v, &e);
        for(int i = 0; i<e; i++){
            int start, end, cost;
            scanf("%d%d%d", &start, &end, &cost);
            edges.push_back({cost, {start, end}});
        }

        sort(edges.begin(), edges.end());
        vector<int> minCost = solve(edges, -1);
        if(minCost.size() != v-1){
            printf("No way\n");
        } else {
            int secondMinCost = 0x3f3f3f3f;
            for(int i: minCost){
                int cost = 0;
                vector<int> secondMin = solve(edges, i);
                if(secondMin.size() == v-1){
                    for(int j: secondMin){
                        cost += edges[j].first;
                    }
                    secondMinCost = min(secondMinCost, cost);
                }
            }

            if(secondMinCost == 0x3f3f3f3f){
                printf("No second way\n");
            } else {
                printf("%d\n", secondMinCost);
            }
        }
    }
}

#include <bits/stdc++.h>

using namespace std;
int M;
int corners[1002];

struct ed{
    int s, d, w;
    bool operator <(const ed& e) const {
        return w < e.w; 
    }
};

unordered_map<int, ed> ump;

int getPar(int n, int (&v)[102]){
    if(v[n] < 0){
        return n;
    }

    int par = getPar(v[n], v);
    v[n] = par;
    return par;
}

bool un(int n1, int n2, int (&v)[102]){
    int par1 = getPar(n1, v);
    int par2 = getPar(n2, v);

    if(par1 == par2){
        return false;
    }

    if(v[par1] < v[par2]){
        v[par1] += v[par2];
        v[par2] = par1;
    } else {
        v[par2] += v[par1];
        v[par1] = par2;
    }
    return true;
}


int main(){
    scanf("%d", &M);
    int e, wght;
    
    for(int j = 1; j<=M; j++){
        scanf("%d", &e);
        for(int i = 0; i<e; i++){
            scanf("%d", &corners[i]);
        }
        corners[e] = corners[0];

        for(int i = 0; i<e; i++){
            scanf("%d", &wght);
            int indx = min(corners[i], corners[i+1])*1009 + max(corners[i], corners[i+1]);
            auto it = ump.find(indx);
            if(it == ump.end()){
                ump.insert(make_pair(indx, ed{j, 0, wght}));
            } else {
                it->second.d = j;
            }
        }
    }

    int a1 = 0, a2 = 0;
    int v1[102];
    int v2[102];
    int vis[M+1] = {false};

    for(int i = 0; i<102; i++){
        v1[i] = -1;
        v2[i] = -1;
    }

    vector<ed> edges;

    for(auto it = ump.begin(); it != ump.end(); ++it){
        edges.push_back(it->second);
    }

    sort(edges.begin(), edges.end());
    for(ed i: edges){
        if(un(i.s, i.d, v1)){
            a1+=i.w;
        }
    }

    for(ed i: edges){
        if(i.d != 0 && un(i.s, i.d, v2)){
            vis[i.s] = true;
            vis[i.d] = true;
            a2+=i.w;
        }
    }

    bool con = true;
    for(int i = 1; i<=M; i++){
        if(!vis[i]){
            con = false;
        }
    }

    if(!con){
        cout<<a1;
    } else {
        cout<<min(a1, a2);
    }
}
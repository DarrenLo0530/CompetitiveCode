#include <bits/stdc++.h>
using namespace std;
map<string, pair<string, int>> ds;

string getPar(string p){
    if(ds[p].first == "-"){
        return p;
    }

    ds[p].first = getPar(ds[p].first);
    return ds[p].first;
}

int un(string p1, string p2){
    string par1 = getPar(p1);
    string par2 = getPar(p2);

    if(par1 == par2){
        return ds[par1].second;
    }

    if(ds[par2].second > ds[par1].second){
        swap(par1, par2);
    }

    ds[par2].first = par1;
    ds[par1].second += ds[par2].second;
    return ds[par1].second;

}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        ds.clear();

        int f;
        scanf("%d", &f);
        while(f--){
            string a, b;
            cin >> a >> b;
            if(!ds.count(a)){
                ds.insert({a, {"-", 1}});
            }


            if(!ds.count(b)){
                ds.insert({b, {"-", 1}});
            }

            printf("%d\n", un(a, b));
        }
    }
}
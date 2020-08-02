#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> edge;

int main(){
    int n, d, m;
    scanf("%d%d%d", &n, &d, &m);

    for(int i = d, y = 0; i<= n; i++, y++){
        edge.insert({i, y});
        edge.insert({y, i});
    }

    for(int i = d, x = 0; i >= 0; i--, x++){
        edge.insert({x, i});
        edge.insert({n - i, n - x});
    }

    
    for(int i = 0; i<m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        
        bool i1, i2, i3, i4;
        i1 = i2 = i3 = i4 = false;

        for(int change = 0; x+change <= n || x-change >= 0 || y + change <= n || y-change >= 0; change++){  
            if(edge.count({x+change, y})){
                i1 = true;
            }

            if(edge.count({x-change, y})){
                i2 = true;
            }

            if(edge.count({x, y + change})){
                i3 = true;
            }

            if(edge.count({x, y - change})){
                i4 = true;
            }
        }

        if(i1 && i2 && i3 && i4){
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }


}
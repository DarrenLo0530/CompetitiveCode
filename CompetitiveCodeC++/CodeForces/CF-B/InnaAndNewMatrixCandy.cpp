#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d%d",&n,&m);

    set<int> ans;
    for(int i = 0; i<n; i++){
        int g, s;
        for(int j = 0; j<m; j++){
            char x;
            scanf(" %c", &x);
            if(x == 'G'){
                g = j;
            } else if(x == 'S'){
                s = j;
            }
        }

        if(s < g){
            printf("-1\n");
            return 0;
        } else {
            ans.insert(s-g);
        }
    }

    printf("%d", ans.size());
}
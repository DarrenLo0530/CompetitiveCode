#include <bits/stdc++.h>
using namespace std;

int tickets[10001][31];

pair<int, int> reduce(int n, int d){
    if(n == 0){
        return {0, 1};
    }
    int g = __gcd(n, d);
    
    return {n/g, d/g};
}

int main(){
    while(true){
        int n, m;
        scanf("%d%d", &n, &m);

        if(n == 0 && m == 0){
            break;
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                scanf("%d", &tickets[i][j]);
            }
        }

        int total = 0;
        for(int i = 0; i<n; i++){
            total += tickets[i][m-1];
        }

        for(int i = 0; i<n; i++){
            pair<int, int> ans = reduce(tickets[i][m-1], total);
            printf("%d / %d\n", ans.first, ans.second);
        }
    }
}
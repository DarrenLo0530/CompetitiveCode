#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll determinantCalculate(int size, ll matrix[5][5]){
    if(size == 2){
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    ll sign = 1;
    ll ans = 0;
    for(int i = 0; i<size; i++){
        ll next[5][5] = {0};

        int added = 0;
        for(int x = 0; x<size; x++){
            if(x == i){
                added = -1;
                continue;
            }

            for(int y = 1; y<size; y++){
                next[y - 1][x + added] = matrix[y][x];
            }
        }

        ans += sign * matrix[0][i] * determinantCalculate(size-1, next);
        sign *= -1;
    }

    return ans;
}
int main(){
    int n;
    scanf("%d", &n);

    while(n--){
        int ab, ac, ad, bc, bd, cd;      
        cin >> ab >> ac >> ad >> bc >> bd >> cd;
        ll matrix[5][5] = {{0, ab*ab, ac*ac, ad*ad, 1}, 
                            {ab*ab, 0, bc*bc, bd*bd, 1}, 
                            {ac*ac, bc*bc, 0, cd*cd, 1}, 
                            {ad*ad, bd*bd, cd*cd, 0, 1}, 
                            {1, 1, 1, 1, 0}};

        ll det = determinantCalculate(5, matrix);
        double ans = sqrt((double) det/288);
        printf("%.4f\n", ans);
    }  
}
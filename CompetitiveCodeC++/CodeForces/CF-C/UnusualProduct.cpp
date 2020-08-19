#include <bits/stdc++.h>
using namespace std;
int nums[1001][1001];
int main(){
    int n;
    scanf("%d", &n);
    for(int i  = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            scanf("%d", &nums[i][j]);
        }
    }

    int sum = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            sum += nums[i][j] * nums[j][i];
            sum %= 2;
        }
    }

    int q;
    scanf("%d", &q);

    for(int i = 0 ; i<q;  i++){
        int o;
        scanf("%d", &o);
        if(o == 3){
            printf("%d", sum);
        } else {
            int x;
            scanf("%d", &x);
            sum ^= 1;
        }
    }
    cout<<'\n';

}
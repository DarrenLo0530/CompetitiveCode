#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f;

int n;
int row[20], col[20];
int dp[20][20];
int ans[20][20];

int solve(int l, int r){
    if(dp[l][r] != -1){
        return dp[l][r];
    }

    if(l >= r){
        return 0;
    }

    for(int i = l; i<r; i++){
        if(col[i] != row[i+1]){
            continue;
        }

        int cost = solve(l, i) + solve(i+1, r) + row[l] * col[r] * col[i];
        if(cost < dp[l][r] || dp[l][r] == -1){
            dp[l][r] = cost;
            ans[l][r] = i;
        }
    }

    return dp[l][r];
}

void res(int l, int r){
    if(l > r){
        return;
    }

    if(l == r){
        printf("A%d", l+1);
        return;
    } 

    cout<<"(";
    res(l, ans[l][r]);
    cout<<" x ";
    res(ans[l][r] + 1, r);
    cout<<")";
}

int main(){
    int cnt = 0;
    while(true){
        scanf("%d", &n);
        if(n == 0){
            break;
        }

        memset(dp, -1, sizeof(dp));
        memset(ans, 0, sizeof(ans));
        
        for(int i = 0; i<n; i++){
            scanf("%d%d", row+i, col+i);
        }
        printf("Case %d: ", ++cnt);
        solve(0, n-1);
        res(0, n-1);
        cout<<'\n';
    }
}
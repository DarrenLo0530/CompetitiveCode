#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int MX = 1e5+10;

int a[MX];
int idx[MX];
int dp[MX];


//dp[x] |= !dp[x + xn];
int n;
int main(){
    scanf("%d", &n);
    
    vector<int> cells;
    for(int i = 1; i<=n; i++) {
        scanf("%d", &a[i]);
        idx[a[i]] = i; 
    }

    for(int i = n; i>=1; i--) {
        for(int j = idx[i] + i; j<=n; j+=i) {
            if(a[j] > i) {
                dp[idx[i]] |= !dp[j];
            }
        }

        for(int j = idx[i] - i ; j >= 1; j-=i) {
            if(a[j] > i) {
                dp[idx[i]] |= !dp[j];
            }
        }
        
    } 


    for(int i = 1; i<=n; i++) {
        printf(dp[i] ? "A" : "B");
    }
    printf("\n");

    
}
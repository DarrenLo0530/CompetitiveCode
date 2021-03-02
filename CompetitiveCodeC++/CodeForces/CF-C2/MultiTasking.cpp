#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

bool used[1001][1001];
int nums[1001][1001];
int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            scanf("%d", &nums[i][j]);
        }
    }

    vector<pii> ans;
    for(int i = k == 0 ? 0 : m-1; k == 0 ? (i < m) : (i >= 0); k == 0 ? i++ : i--){
        for(int j = i; k == 0 ? j<m : j >= 0; k == 0 ? j++ : j--){
            if(j == i){
                continue;
            }
            ans.push_back({i, j});
        }
    }

    printf("%d\n", ans.size());
    for(pii x: ans){
        printf("%d %d\n", x.first+1, x.second+1);
    }
    
}
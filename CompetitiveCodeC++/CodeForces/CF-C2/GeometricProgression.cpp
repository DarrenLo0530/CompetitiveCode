#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int seq[200001];
ll dp[4][200001];
int main(){
    vector<pii> sorted;
    int n, k;

    scanf("%d%d", &n, &k);

    for(int i = 0; i<n; i++){
        scanf("%d", seq + i);
        sorted.push_back({seq[i], i});
    }
    sort(sorted.begin(), sorted.end());

    for(int i = 0; i<n; i++){
        dp[1][i] = 1;
        auto prev = lower_bound(sorted.begin(), sorted.end(), make_pair(seq[i], i));
        if(prev != sorted.begin()){
            prev--;
            if(prev->first == seq[i]){
                dp[1][i] += dp[1][prev->second];
                dp[2][i] += dp[2][prev->second];
            }
        }


        if(seq[i] % k == 0){
            prev = lower_bound(sorted.begin(), sorted.end(), make_pair(seq[i]/k, i));
            if(prev != sorted.begin() && (--prev)->first == seq[i]/k){
                dp[2][i] += dp[1][prev->second];
                dp[3][i] += dp[2][prev->second];
            }
        }
    }

    /*
    for(int i = 1; i<=3; i++){
        for(int j = 0; j<n; j++){
            printf("%d ", dp[i][j]);
        }

        printf("\n");
    }
    */

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += dp[3][i];
    }

    printf("%lld\n", ans);


}
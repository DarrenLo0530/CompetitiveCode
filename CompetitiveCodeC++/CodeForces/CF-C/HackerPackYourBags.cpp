#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<pair<int, pii>> vouchers;
vector<pii> diffArr[200010];
vector<int> minCost[200010];
int main(){
    int n, x;
    scanf("%d%d", &n, &x);
    for(int i = 0; i<n; i++){
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        vouchers.push_back(make_pair(l, make_pair(r, c)));
    }   

    sort(vouchers.begin(), vouchers.end());
    for(int i = 0; i<n; i++){
        int l = vouchers[i].first;
        int r = vouchers[i].second.first;
        int c = vouchers[i].second.second;
        diffArr[r-l+1].push_back({l, c});
    }

    for(int i = 0; i<200010; i++){
        if(diffArr[i].size() == 0){
            continue;
        }

        minCost[i].push_back(diffArr[i].back().second);
        for(int j = diffArr[i].size() - 2; j>=0; j--){
            minCost[i].push_back(min(minCost[i].back(), diffArr[i][j].second));
        }
        reverse(minCost[i].begin(), minCost[i].end());
    }

    int ans = 2*0x3f3f3f3f;
    for(int i = 0; i<n; i++){
        int l = vouchers[i].first;
        int r = vouchers[i].second.first;
        int c = vouchers[i].second.second;
        int find = x - (r-l+1);
        if(find <= 0 || minCost[find].size() == 0){
            continue;
        }
        
        int idx = upper_bound(diffArr[find].begin(), diffArr[find].end(), make_pair(r, 2*0x3f3f3f3f)) - diffArr[find].begin();
        if(idx < minCost[find].size()){
            ans = min(ans, c+minCost[find][idx]);
        }
    }

    if(ans == 2*0x3f3f3f3f){
        printf("%d\n", -1);
    } else {
        printf("%d\n", ans);
    }
}
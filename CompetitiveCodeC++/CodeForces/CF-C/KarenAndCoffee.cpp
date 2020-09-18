#include <bits/stdc++.h>
using namespace std;
const int MX = 200001;
int cnt[MX], psa[MX];

int main(){
    int n, k, q;
    scanf("%d%d%d", &n, &k, &q);
    for(int i = 0; i<n; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        cnt[l]++;
        cnt[r + 1]--;
    }
    for(int i = 1; i<MX; i++){
        cnt[i] += cnt[i-1];
    }
    for(int i = 0; i<MX; i++){
        psa[i+1] = psa[i];
        if(cnt[i] >= k){
            psa[i + 1]++;
        }
    }

    for(int i = 0; i<q; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        int ans = psa[r+1] - psa[l];
        printf("%d\n", ans);
    }

}
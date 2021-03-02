#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int MX = 1e6 + 1;
int l[MX], r[MX];
int n, m;


bool numPairs(int ugliness){
    int ans = 0;
    int rShoe = 0;
    for(int i = 0; i<n && rShoe < m; i++){
        while(rShoe < m && abs(l[i] - r[rShoe]) > ugliness){
            rShoe++;
        }
        if(rShoe < m){
            ans++;
            rShoe++;
        }
    }

    return ans == n;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i =0; i<n; i++){
        scanf("%d", l + i);
    }    
    for(int i = 0; i<m; i++){
        scanf("%d", r + i);
    }

    if(n > m){
        swap(n, m);
        swap(l, r);
    }

    sort(l, l+n);
    sort(r, r+m);

    int lo = 0, hi = 1e9;

    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(numPairs(mid)){
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }

    printf("%d\n", lo);



}
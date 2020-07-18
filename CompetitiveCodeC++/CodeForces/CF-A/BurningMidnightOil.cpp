#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;

ll kPows[100];

int getSum(int v){
    int ans = 0;
    for(int i = 0; i<=32; i++){
        if(v/kPows[i] == 0){
            break;
        }
        ans += v/kPows[i];
    }
    return ans;
}

int bin(int l, int r, int search){
    if(l == r){
        return l;
    }
    int mid = (l+r)/2;
    int s = getSum(mid);
    if (s >= n){
        return bin(l, mid, search);
    } else {
        return bin(mid+1, r, search);
    }
}

int main(){
    scanf("%lld%lld", &n, &k);
    kPows[0] = 1;
    for(int i = 1; i < 33; i++){
        kPows[i] = kPows[i-1] * k;
    }
    printf("%d", bin(0, n, n));

}
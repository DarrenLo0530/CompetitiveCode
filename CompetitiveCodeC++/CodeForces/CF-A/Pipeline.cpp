#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;

ll sum(ll l, ll r){
    return (l + r)/2.0 * (r-l+1);
}

int search(){
    int l = 1;
    int r = k;

    while(l < r){
        int mid = (l+r)/2;
        if(sum(mid, k) == n){
            return k - mid + 1;
        } else if(sum(mid, k) > n){
            l = mid+1;
        } else {
            r = mid;
        }
        
    }
    return k - l + 2;    
}

int main(){
    cin >> n >> k;
    if(n == 1){
        cout << "0" << '\n';
    } else if(n <= k){
        cout << "1" << '\n';
    } else {
        k--;
        n--;
        if(sum(1, k) < n){
            cout << -1 << '\n';
        } else {
            cout << search() << "\n";
        }
    }
}
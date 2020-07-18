#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<int, int> nums[100001];
int find(int l, int r, int search){
    if(l == r){
        return nums[l].second;
    }

    int mid = (l + r)/2;

    if(nums[mid].first == search){
        return nums[mid].second;
    } else if(nums[mid].first > search){
        return find(l, mid-1, search);
    } else {
        return find(mid+1, r, search);
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++){
        int x;
        scanf("%d", &x);
        nums[i] = make_pair(x, i);
    }

    sort(nums+1, nums + n+1);

    int m;
    cin >> m;

    ll v = 0;
    ll p = 0;
    for(int i = 0; i<m; i++){
        int s;
        cin>>s;
        int pos = find(1, n, s);
        v += pos;
        p += n - pos + 1;
    }
    cout << v << " " << p << '\n';


}
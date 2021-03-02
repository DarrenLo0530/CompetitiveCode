#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int nums[100001];
int main(){
    ll n;
    ll k;
    cin >> n >> k;
    for(int i = 0; i<n; i++){
        scanf("%d", nums + i);
    }

    sort(nums, nums + n);
    for(int i = 0; i<n; i++){
        int start = i;
        int curr = nums[i];
        ll cnt = 1;
        while(nums[i+1] == curr){
            cnt++;
            i++;
        }
        if(k - cnt*n <= 0){
            printf("%d %d\n", curr, nums[(k-1)/cnt]);
            return 0;
        }
        k -= cnt*n;
    }
}
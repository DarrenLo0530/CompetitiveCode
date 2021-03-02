#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

ll nums[100001];
int main(){
    int n, k;
    scanf("%d%d", &n, &k);

    for(int i = 1; i<=n; i++){
        scanf("%lld", nums + i);
    }
    sort(nums+1, nums+n+1);
    vector<ll> psa;
    psa.push_back(0);
    for(int i = 1; i<=n; i++){
        psa.push_back(nums[i] + psa.back());
    }
    
    int appearances = 0;
    int num = 0;
    int l = 1;
    for(int i = 1; i<=n; i++){
        while((nums[i] * (i - l) - (psa[i-1] - psa[l-1])) > k){
            l++;
        }
        if(i - l + 1 > appearances){
            num = nums[i];
            appearances = i-l+1;
        }

    }

    printf("%d %d\n", appearances, num);

}
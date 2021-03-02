#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int MX = 2e5 + 10;
int app[MX];
bool used[MX];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);

    vector<int> nums;
    for(int i = 0; i<n; i++) {
        int x;
        scanf("%d", &x);
        nums.push_back(x);
        app[x] = i;
    }

    vector<int> ans;
    for(int i = 0; i<n; i++) {
        
        if(!used[nums[i]]) {
                while(!ans.empty() && ans.back() > nums[i] && i < app[ans.back()]) {
                used[ans.back()] = false;
                ans.pop_back();
            }

            used[nums[i]] = true;
            ans.push_back(nums[i]);
        }
    }

    for(int i = 0; i<k; i++) {
        if(i) {
            printf(" %d", ans[i]);
        } else {
            printf("%d", ans[i]);
        }
    }
    printf("\n");
    

    
}
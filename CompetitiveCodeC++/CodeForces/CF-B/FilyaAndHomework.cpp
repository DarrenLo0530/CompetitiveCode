#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    set<int> filter;
    vector<int> nums;
    while(n--){
        int x;
        scanf("%d", &x);
        if(!filter.count(x)){
            nums.push_back(x);
            filter.insert(x);
        }
    }

    sort(nums.begin(), nums.end());

    if(nums.size() <= 2){
        printf("YES\n");
    } else if(nums.size() == 3){
        if((double)(nums[0] + nums[2])/2 == nums[1]){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    } else {
        printf("NO\n");
    }

    
}
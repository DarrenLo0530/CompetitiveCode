#include <bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        set<int> temp;
        vector<int> nums;

        int n;
        scanf("%d", &n);
        if(n == 0){
            break;
        }

        for(int i = 0; i<n; i++){
            int x;
            scanf("%d", &x);
            nums.push_back(x);
        }   


        int total = n*(n-1)/2;
        int nonCommon = 0;
        
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                if(__gcd(nums[i], nums[j]) == 1){
                    nonCommon++;
                }
            }
        }

        if(nonCommon == 0){
            printf("No estimate for this data set.\n");
        } else {
            double ans = sqrt((double)total*6/nonCommon);
            printf("%.6f\n", ans);
        }

        



    }

        
}
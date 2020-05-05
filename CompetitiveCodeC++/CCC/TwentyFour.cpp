#include <bits/stdc++.h>
using namespace std;
int ans;
vector<int> nums(4);
bool divAllowed(int num1, int num2){
    if(num2 != 0 && num1 % num2 == 0){
        return true;
    }
    return false;
}

void getAns(int res, int lvl){
    if(lvl == 4){
        if(res <= 24){
            ans = max(ans, res);
        }
        return;
    }

    if(lvl == 0){
        getAns(nums[lvl], lvl+1);
        return;
    } 
    
    if(lvl <= 3){
        getAns(res * nums[lvl], lvl+1);
        getAns(res - nums[lvl], lvl+1);
        getAns(res + nums[lvl], lvl+1);
        if(divAllowed(res, nums[lvl])){
            getAns(res/nums[lvl], lvl+1);
        }
    }

    if(lvl <= 2){
        getAns(res * (nums[lvl] + nums[lvl+1]), lvl+2);
        getAns(res * (nums[lvl] - nums[lvl+1]), lvl+2);
        getAns(res + (nums[lvl] * nums[lvl+1]), lvl+2);
        getAns(res - (nums[lvl] * nums[lvl+1]), lvl+2);

        if(divAllowed(res, nums[lvl] + nums[lvl+1])){
            getAns(res / (nums[lvl] + nums[lvl+1]), lvl+2);
        }
        if(divAllowed(res, nums[lvl] - nums[lvl+1])){
            getAns(res / (nums[lvl] - nums[lvl+1]), lvl+2);
        }

        if(divAllowed(nums[lvl], nums[lvl+1])){
            getAns(res + (nums[lvl] / nums[lvl+1]), lvl+2);
            getAns(res - (nums[lvl] / nums[lvl+1]), lvl+2);
        }
    }
}

int main(){
    int N;
    scanf("%d", &N);
    for(int k = 0; k<N; k++){
        ans = 0;
        for(int i = 0; i<4; i++){
            scanf("%d", &nums[i]);
        }

        sort(nums.begin(), nums.end());
        do{
            getAns(0, 0);
        } while (next_permutation(nums.begin(), nums.end()));
        printf("%d\n", ans);
    }
}
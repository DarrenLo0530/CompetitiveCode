#include <bits/stdc++.h>
using namespace std;


int nums[5];
bool used[5];

bool possible(int prev){
    bool ans = false;

    bool usedAll = true;
    for(int i = 0; i<5; i++){
        usedAll &= used[i];
    }

    if(usedAll){
        if(prev == 23){
            return true;
        } 
        return false;
    }


    for(int i = 0; i<5; i++){
        if(!used[i]){
            used[i] = true;
            ans |= possible(prev * nums[i]);
            ans |= possible(prev + nums[i]);
            ans |= possible(prev - nums[i]);
            used[i] = false;
        }
    }

    return ans;
}

int main(){
    while(true){
        memset(used, false, sizeof(used));
        for(int i = 0; i<5; i++){
            scanf("%d", nums + i);
        }

        bool leave = true;
        for(int i = 0; i<5; i++){
            leave &= !nums[i];
        }

        if(leave){
            break;
        }

        bool ans = false;
        for(int i = 0; i<5; i++){
            used[i] = true;
            ans |= possible(nums[i]);
            used[i] = false;
        }

        if(ans){
            cout<<"Possible\n";
        } else {
            cout<<"Impossible\n";
        }
    }
}
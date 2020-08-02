#include <bits/stdc++.h>
using namespace std;

vector<int> nums[100003];
vector<pair<int, int>> answers;

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 1; i<=n; i++){
        int x;
        scanf("%d", &x);
        nums[x].push_back(i);
    }   

    

    int count = 0;

    for(int i = 1; i<100003; i++){
        if(nums[i].size() == 0){
            continue;
        } else if(nums[i].size() == 1){
            count++;
            answers.push_back({i, 0});
        } else {
            bool series = true;
            int commonDiff = nums[i][1] - nums[i][0];
            for(int j = 2; j<nums[i].size(); j++){
                if(nums[i][j] - nums[i][j-1] != commonDiff){
                    series = false;
                    break;
                }
            }

            if(series){
                count++;
                answers.push_back({i, commonDiff});
            }
        }
    }

    printf("%d\n", count);
    for(auto a: answers){
        printf("%d %d\n", a.first, a.second);
    }
}
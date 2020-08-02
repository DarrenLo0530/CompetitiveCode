#include <bits/stdc++.h>
using namespace std;

struct Ranking{
    int a, b;
    bool operator <(const Ranking &r1) const {
        return b > r1.b;
    }
};

int main(){
    int n;
    scanf("%d", &n);

    vector<Ranking> nums;

    while(n--){
        int a, b;
        scanf("%d%d", &a, &b);
        nums.push_back(Ranking{a,b});        
    }

    stable_sort(nums.begin(), nums.end());
    
    for(auto i: nums){
        printf("%d %d\n", i.a, i.b);
    }
}
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> nums;
int main(){
    int x;
    scanf("%d", &x);
    //If n is even, then odd is always optimal

    for(int i = 1; i<=100; i+=2){
        nums.push_back({i*i - (i*i)/2, i});
    }

    pair<int, int> ans = *lower_bound(nums.begin(), nums.end(), make_pair(x, -1));
    int best = ans.second;
    if(x == 3){
        best = 5;
    }
    printf("%d\n", best);


}
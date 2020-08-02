#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

int main(){
    while(true){
        int m, n;
        scanf("%d%d", &m, &n);
        if(m == 1 && n == 1){
            break;
        }

        pair<int, int> frac = {m, n};
        double search = (double)m/n;

        string ans = "";

        vector<pair<int, int>> nums;
        nums.push_back({1, 1});

        while(true){
            pair<int, int> prev = nums[nums.size() - 1];
            double comp = (double) prev.first/prev.second;
            if(prev == frac){
                break;
            } else if(search > comp){
                ans = "R" + ans;
                int mostRecent = ans.find('L');
                if(mostRecent == string::npos){
                    nums.push_back({prev.first + 1, prev.second});
                } else {
                    pair<int, int> add = nums[nums.size() - 1 - mostRecent];
                    pair<int, int> next = {prev.first + add.first, prev.second + add.second};
                    nums.push_back(next);
                }
            } else {
                ans = "L" + ans;
                int mostRecent = ans.find('R');
                if(mostRecent == string::npos){
                    nums.push_back({prev.first, prev.second + 1});
                } else {
                    pair<int, int> add = nums[nums.size() - 1 - mostRecent];
                    pair<int, int> next = {prev.first + add.first, prev.second + add.second};
                    nums.push_back(next);
                }
            }
        }

        reverse(ans.begin(), ans.end());
        cout << ans << '\n';

    }
}
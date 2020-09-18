#include <bits/stdc++.h>
using namespace std;
int n, k, x;

int solve(vector<int> balls){
    bool destroyed = true;
    while(destroyed){
        destroyed = false;
        for(int start = 0; start<balls.size(); start++){
            int end = start+1;
            while(balls[end] == balls[end-1]){
                end++;
            }
            end--;
            if(end - start >= 2){
                destroyed = true;
                balls.erase(balls.begin() + start, balls.begin() + end + 1);
                break;
            } else {
                start = end;
            }
        }
    }

    return n - (balls.size() - 1);
}
int main(){
    vector<int> balls;
    scanf("%d%d%d", &n, &k, &x);
    for(int i = 0; i<n; i++){
        int a;
        scanf("%d", &a);
        balls.push_back(a);
    }

    balls.push_back(100000);

    int ans = 0;
    for(int i = 0; i<n+1; i++){
        vector<int> copy = balls;
        
        copy.insert(copy.begin() + i, x);
        ans = max(ans, solve(copy));
    }

    printf("%d\n", ans);
}
#include <bits/stdc++.h>
using namespace std;

int dp[27];
vector<pair<int, int>> keys[27];
double euclideanDistance(int key){
    double minDist = 0x3f3f3f3f;
    for(auto p1: keys[key]){
        for(auto p2: keys[26]){
            minDist = min(minDist, sqrt((double) pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2)));
        }
    }

    return minDist;
}

int solve(string s, int x){
    int ans = 0;

    for(char c: s){
        if(c - 'a' >= 0 && c-'a' <= 25){
            //Letter doesnt exist on keyboard
            if(keys[c-'a'].size() == 0){
                return -1;
            }
        } else {
            if(keys[tolower(c) - 'a'].size() == 0 || keys[26].size() == 0){
                return -1;
            }

            if(dp[tolower(c)-'a'] != 0){
                if(dp[tolower(c)-'a'] == 1){
                    ans++;
                }
            } else if(euclideanDistance(tolower(c)-'a') > x){
                dp[tolower(c)-'a'] = 1;      
                ans++;
            } else {
                dp[tolower(c)-'a'] = 2;
            }

        }
    }
    
    return ans;
}
int main(){
    int n, m, x;
    scanf("%d%d%d", &n, &m, &x);

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            char c;
            scanf(" %c", &c);
            if(c == 'S'){
                keys[26].push_back({j, i});
            } else {
                keys[c - 'a'].push_back({j, i});
            }
        }
    }

    int l;
    scanf("%d", &l);
    string s;
    cin >> s;

    printf("%d\n", solve(s, x));
}

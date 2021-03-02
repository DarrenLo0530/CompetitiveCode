#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
vector<string> f, s;

bool isAlpha(char c){
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9';
}

int dp[1001][1001];


int main(){
    string first, second;
    int cnt = 0;
    while(getline(cin, first) && getline(cin, second)){
        f.clear();
        s.clear();
        memset(dp, 0, sizeof(dp));
        printf("%2d. ", ++cnt);

        if(first == "" || second == ""){
            printf("Blank!\n");
            continue;
        }

        first += "$";
        second += "$";

        for(int i = 0; i<first.size(); i++){
            if(!isAlpha(first[i])){
                continue;
            }

            for(int j = 0; j<first.size(); j++){
                if(!isAlpha(first[i + j])){
                    f.push_back(first.substr(i, j));
                    i = i+j;
                    break;
                }
            }
        }

        for(int i = 0; i<second.size(); i++){
            if(!isAlpha(second[i])){
                continue;
            }

            for(int j = 0; j<second.size(); j++){
                if(!isAlpha(second[i + j])){
                    s.push_back(second.substr(i, j));
                    i = i+j;
                    break;
                }
            }
        }

        for(int i = 1; i<=f.size(); i++){
            for(int j = 1; j<=s.size(); j++){
                if(f[i-1] == s[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i<=f.size(); i++){
            for(int j = 0; j<=s.size(); j++){
                ans = max(ans, dp[i][j]);
            }
        }

        printf("Length of longest match: %d\n", ans);
    }
}
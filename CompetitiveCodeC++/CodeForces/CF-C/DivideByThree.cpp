#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int dp[3][100010];
int nums[100010];
int cameFrom[3][100010];

int main(){
    memset(dp, INF, sizeof(dp));
    string s;
    cin >> s;
    for(int i = 0; i<s.size(); i++){
        nums[i] = s[i] - '0';
    }
    dp[0][0] = 0;


    for(int j = 0; j<s.size(); j++){
        //Use the number
        for(int i = 0; i<3; i++){
            if(!(nums[j] == 0 && dp[i][j] == j) || (nums[j] == 0 && dp[i][j] == j && j == s.size() - 1)){

                if(dp[i][j] < INF && dp[(i + nums[j]) % 3][j+1] > dp[i][j]){
                    dp[(i + nums[j]) % 3][j+1] = dp[i][j];
                    cameFrom[(i + nums[j]) % 3][j+1] = i;
                }
            }
        }
        
        //Ditch the number
        for(int i = 0; i<3; i++){
            if(dp[i][j] + 1 < dp[i][j+1]){
                dp[i][j+1] = dp[i][j] + 1;
                cameFrom[i][j+1] = i;
            }
        }
    }
    /*
    for(int i = 0; i<3; i++){
        for(int j = 0; j<=s.size(); j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<'\n';
    }

    for(int i = 0; i<3; i++){
        for(int j = 0; j<=s.size(); j++){
            cout<<cameFrom[i][j]<<" ";
        }
        cout<<'\n';
    }
    */
    

    string ans = "";
    int currM = 0;
    for(int i = s.size(); i>=1; i--){
        int prev = cameFrom[currM][i];
        if(dp[prev][i-1] == dp[currM][i]){
            ans = s[i-1] + ans;
        }

        currM = prev;
        
    }

    if(ans == ""){
        if(s.find('0') != string::npos){
            cout<<0<<"\n";
        } else {
            cout<<-1<<"\n";
            return 0;
        }
    
    }

    cout<<ans<<'\n';
}
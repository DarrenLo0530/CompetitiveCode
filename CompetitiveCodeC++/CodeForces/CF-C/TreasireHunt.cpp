#include <bits/stdc++.h>
using namespace std;

int maxLetters[3];
int letterCnt[3][52];
string s[3];
int ans[3];

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i<3; i++){
        cin >> s[i];
        for(int j = 0; j<s[i].size(); j++){
            if(s[i][j] >= 'a' && s[i][j] <= 'z'){
                letterCnt[i][s[i][j] - 'a']++;
            } else {
                letterCnt[i][s[i][j] - 'A' + 26]++;
            }
        }
    }
    int l = s[0].size();

    for(int i = 0; i<3; i++){
        for(int j = 0; j<52; j++){
            if(letterCnt[i][j] == l){
                if(n == 1){
                    ans[i] = max(ans[i], l-1);
                } else {
                    ans[i] = max(ans[i], l);
                }
            } else if(letterCnt[i][j] + n > l){
                ans[i] = max(ans[i], l);
            } else {
                ans[i] = max(ans[i], n + letterCnt[i][j]);
            }
        }
    }

    if(ans[0] > ans[1] && ans[0] > ans[2]){
        cout<<"Kuro\n";
    } else if(ans[1] > ans[0] && ans[1] > ans[2]){
        cout<<"Shiro\n";
    } else if(ans[2] > ans[0] && ans[2] > ans[1]){
        cout<<"Katie\n";
    } else {
        cout<<"Draw\n";
    }

}
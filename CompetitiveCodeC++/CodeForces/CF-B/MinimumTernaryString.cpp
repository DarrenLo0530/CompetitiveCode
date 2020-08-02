#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int oneCounter = 0;
    string ans = "";

    for(int i = 0; i<s.size(); i++){
        if(s[i] == '2'){
            ans += '2';
        } else if(s[i] == '1'){
            oneCounter++;
        } else {
            ans += '0';
        }
    }

    int first = ans.find('2');
    if(first == string::npos){
        first = ans.size();
    }
    ans = ans.substr(0, first) + string(oneCounter, '1') + ans.substr(first);
    cout<<ans;
}
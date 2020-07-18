#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;

    string ans = "";
    for(int i = 0; i<s.length(); i++){
        if(n % 2 == 0){
            if(i % 2 == 0){
                ans = s[i] + ans;
            } else {
                ans = ans + s[i];
            }
        } else {
            if(i % 2 != 0){
                ans = s[i] + ans;
            } else {
                ans = ans + s[i];
            }
        }
    }
    cout<<ans<<'\n';
}
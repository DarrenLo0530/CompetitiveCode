#include <bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    
    int ans = (1<<s.size()) - 1;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '7'){
            ans += (1 << i);
        }
    }

    cout<<ans;

}

#include <bits/stdc++.h>
using namespace std;

string sumDigits(string n){
    int ans = 0;
    stringstream ss;
    

    for(int i = 0; i<n.length(); i++){
        ans += n.at(i) - '0';
    }
    ss << ans;
    return ss.str();
}
int main(){
    string n;
    cin >> n;

    int ans = 0;
    while(n.length() != 1){
        n = sumDigits(n);
        ans++;
    }

    printf("%d\n", ans);
}
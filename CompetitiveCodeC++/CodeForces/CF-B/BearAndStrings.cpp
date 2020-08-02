#include <bits/stdc++.h>
using namespace std;

vector<int> starts;
int main(){
    string s;
    cin >> s;
    int ans = 0;
    int startSearch = 0;
    int prevStart = -1;
    while(true){
        int found = s.find("bear", startSearch);
        if(found == string::npos){
            break;
        } else {
    
            ans += (found - prevStart) * (s.size() - (found + 3));            
            prevStart = found;
            startSearch = found + 4;
        }
    }
    printf("%d\n", ans);
    
}
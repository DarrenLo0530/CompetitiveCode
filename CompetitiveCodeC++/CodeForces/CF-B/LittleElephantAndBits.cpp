#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    bool removed = false;
    for(auto it = s.begin(); it != s.end(); ++it){
        if(*it == '0'){
            s.erase(it);
            removed = true;
            break;
        }
    }

    if(!removed){
        auto it = s.begin();
        s.erase(it);
    }

    cout<<s;
}
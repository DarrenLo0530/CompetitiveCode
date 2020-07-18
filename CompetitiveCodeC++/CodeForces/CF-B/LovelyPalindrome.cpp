#include <bits/stdc++.h>
using namespace std;

int main(){
    string n;
    cin >> n;
    string r = n;
    reverse(r.begin(), r.end());

    string ans = n + r;
    cout << ans;
}
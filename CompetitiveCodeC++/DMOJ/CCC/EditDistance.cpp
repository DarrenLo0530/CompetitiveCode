#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int main(){
    string a, s;
    cin >> a >> s;

    string k = s;

    set<string> ans;

    for(char c: a) {
        for(int i = 0; i<=s.size(); i++) {
            ans.insert(s.substr(0, i) + c + s.substr(i, s.size() - i));
        }
    }

    for(int i = 0; i<s.size(); i++) {
        for(char c: a) {
            ans.insert(s.substr(0, i) + c + s.substr(i+1, s.size() - i));
        }
        ans.insert(s.substr(0, i) + s.substr(i+1, s.size() - 1));
    }

    for(string s: ans) {
        if(s != k) {
            cout << s << "\n";

        }
    }

}
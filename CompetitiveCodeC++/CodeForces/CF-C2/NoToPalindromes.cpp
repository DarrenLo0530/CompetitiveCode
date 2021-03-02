#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int main(){
    int n, p;
    string s;
    scanf("%d%d", &n, &p);
    cin >> s;

    int index = -1;
    for(int i = s.size()-1; i>=0 && index == -1; i--){
        for(char x = s[i]+1; x < 'a' + p && index == -1; x++){
            if(x != s[max(0, i-1)] && x != s[max(0, i-2)]){
                index = i;
                s[i] = x;
            }
        }
    }

    if(index == -1){
        cout << "NO\n";
        return 0;
    }

    for(int i = index+1; i<s.size(); i++){
        for(char x = 'a'; x < 'a' + p; x++){
            if(x != s[max(0, i-1)] && x != s[max(0, i-2)]){
                s[i] = x;
                break;
            }
        }
    }

    cout << s << '\n';
}
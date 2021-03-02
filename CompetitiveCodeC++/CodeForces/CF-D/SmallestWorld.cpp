#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int main(){
    string s;
    cin >> s;

    printf("%d", 1);
    vector<int> num;
    for(int i = 0; i<s.size(); i++) {
        num.push_back(s[i] == 'a' ? 0 : 1);
    }

    for(int i = 1; i<s.size(); i++) {
        if(i + 1 >= s.size()) {
            printf(" %d", num[i] == 0 ? 1 : 0);
        } else if(num[i] == num[i+1]) {
            printf(" %d", 0);
        } else {
            printf(" %d", 1);
        }
    }
    
    printf("\n");
}
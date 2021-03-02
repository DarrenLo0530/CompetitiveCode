#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int main(){
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    
    vector<string> min;
    for(int i = 0; i<n; i++){
        string next = "";
        int add = 10 - (s[i] - '0');
        for(int j = 0; j<n; j++){
            int currIdx = (i + j) % n;
            next += ((s[currIdx] - '0') + add) % 10 + '0';
        }
        min.push_back(next);
    }
    

    sort(min.begin(), min.end());
    cout << min[0] << '\n';
}
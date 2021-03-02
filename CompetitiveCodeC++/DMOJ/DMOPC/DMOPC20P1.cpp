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
    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        if(s.find('C') != string::npos && s.find('M') != string::npos){
            printf("NEGATIVE MARKS\n");
        } else if(s.find('C') != string::npos || s.find('M') != string::npos){
            printf("FAIL\n");
        } else {
            printf("PASS\n");
        }
    }
}
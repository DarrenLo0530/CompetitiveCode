#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

string can(string &curr, int l, int r){
    vector<string> encoding;

    for(int i = l; i<=r; i++){
        int lvl = 0;    
        int j;
        for(j = i; j<=r; j++){
            if(curr[j] == '0'){
                lvl++;
            } else {
                lvl--;
            }
            if(lvl == 0){
                encoding.push_back(can(curr, i+1, j-1));
                break;
            }
        }
        i = j;
    }

    sort(encoding.begin(), encoding.end());
    string ans = "";
    for(string s: encoding){
        ans += s;
    }
    ans = "(" + ans + ")";
    return ans;
}


int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        string a, b;
        cin >> a >> b;
        string first = can(a, 0, a.size()-1);
        string second = can(b, 0, b.size()-1);
        printf(first == second ? "same\n" : "different\n");
    }



}
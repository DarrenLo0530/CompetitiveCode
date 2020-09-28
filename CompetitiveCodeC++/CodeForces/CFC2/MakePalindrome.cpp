#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int dp[1005][1005];
int path[1005][1005];
string s;

int minInsertion(int l, int r){
    if(l >= r){
        return 0;
    }

    if(dp[l][r] != -1){
        return dp[l][r];
    }

    if(s[l] == s[r]){
        path[l][r] = 0;
        return dp[l][r] = minInsertion(l+1, r-1);
    } else {
        int a1 = 1 + minInsertion(l+1, r);
        int a2 = 1 + minInsertion(l, r-1);
        if(a1 < a2){
            path[l][r] = 1;
            return dp[l][r] = a1;
        } else {
            path[l][r] = 2;
            return dp[l][r] = a2;
        }
    }
}

void printAns(int l, int r){
    if(l >= r){
        if(l == r){
            cout<<s[l];
        }
        return;
    }
    if(path[l][r] == 0){
        cout << s[l];
        printAns(l+1, r-1);
        cout << s[r];
    } else if(path[l][r] == 1){
        cout << s[l];
        printAns(l+1, r);
        cout << s[l];
    } else {
        cout << s[r];
        printAns(l, r-1);
        cout << s[r];
    }
}

int main(){
    while(cin >> s){
        memset(dp, -1, sizeof(dp));
        memset(path, 0, sizeof(path));
        cout<<minInsertion(0, s.size()-1)<<" ";
        printAns(0, s.size()-1);
        cout<<"\n";
    }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> ans;
void solve(ll curr, int numNonZero, int currIdx){
    if(currIdx == 18){
        ans.push_back(curr);
        return;  
    }

    solve(curr*10, numNonZero, currIdx+1);
    if(numNonZero < 3){
        for(int i = 1; i<=9; i++){
            solve(curr*10 + i, numNonZero+1, currIdx+1);
        }
    }

}

int main(){
    int n;
    scanf("%d", &n);
    solve(0, 0, 0);
    ans.push_back(1000000000000000000);

    for(int i = 0; i<n; i++){
        ll l, r;
        cin >> l >> r;
        ll dif = (upper_bound(ans.begin(), ans.end(), r) - ans.begin()) - (lower_bound(ans.begin(), ans.end(), l) - ans.begin());
        cout<<dif<<'\n';
    }
}
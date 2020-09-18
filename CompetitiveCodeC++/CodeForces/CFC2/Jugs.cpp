#include <bits/stdc++.h>
using namespace std;
bool used[1010][1010];
int a, b, c;
vector<string> ans;
bool solve(int l, int r){
    if(r == c){
        ans.push_back("success");
        return true;
    }
    used[l][r] = true;
    //Fill a
    if(!used[a][r] && solve(a, r)){
        ans.push_back("fill A");
    } else if(!used[l][b] && solve(l, b)){
        ans.push_back("fill B");
    } else if(!used[max(0, l-(b-r))][r + min(l, b-r)] && solve(max(0, l-(b-r)), r + min(l, b-r))){
        ans.push_back("pour A B");
    } else if(!used[l + min(r, a-l)][max(0, r-(a-l))] && solve(l + min(r, a-l), max(0, r-(a-l)))){
        ans.push_back("pour B A");
    } else if(!used[0][r] && solve(0, r)){
        ans.push_back("empty A");
    } else if(!used[l][0] && solve(l, 0)){
        ans.push_back("empty B");
    } else {
        return false;
    }

    return true;
}
int main(){
    while(cin >> a >> b >> c){
        memset(used, false, sizeof(used));
        ans.clear();
        solve(0, 0);
        for(int i = ans.size()-1; i>=0; --i){
            cout << ans[i] << "\n";
        }
    }
}
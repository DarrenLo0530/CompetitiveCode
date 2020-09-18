#include <bits/stdc++.h>
using namespace std;
void solve(int n){
    n--;
    if(n <= 1){
        return;
    }  

    bool printed = false;
    vector<pair<int, int>> ans;

    for(int i = 2; i*i <=n; i++){
        int cnt = 0;
        while(n % i == 0){
            cnt++;
            n/=i;
        }
        if(cnt == 0){
            continue;
        }

        ans.push_back({i, cnt});
    }

    if(n != 1){
        ans.push_back({n, 1});
    }

    reverse(ans.begin(), ans.end());
    for(int i = 0; i<ans.size(); i++){
        if(i != 0){
            cout<<" ";
        }

        cout<<ans[i].first<<" "<<ans[i].second;
    }

    cout<<'\n';

}
int main(){
    string s;
    while(getline(cin, s)){
        if(s[0] == '0'){
            break;
        }
        stringstream sstream(s);
        int p, e;
        int num = 1;
        while(sstream >> p >> e){
            num *= pow(p, e);
        }
        solve(num);
    }
}
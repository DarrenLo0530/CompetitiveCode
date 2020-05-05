#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
map<string, vector<pair<char, int>>> funcs;
vector<string> names;


long long runFunc(vector<pair<char, int>> opps, long long curr){
    for(auto i: opps){
        if(i.first == 'a'){
            curr += i.second;  
            curr %= mod;
        } else if(i.first == 's'){
            curr -= i.second;
            curr %= mod;
        } else if(i.first == 'm'){
            curr *= i.second;
            curr %= mod;
        } else {
            int funcIdx = i.second;
            curr = runFunc(funcs.at(names[funcIdx]), curr);
        }
    }

    return curr;
}
int main(){
    int T;
    cin>>T;


    for(int i = 0; i<T; i++){
        funcs.clear();
        names.clear();
        string J;
        long long ans = 0;
        string currFunc = "";
        int N;
        cin>>N;
        for(int j = 0; j<N; j++){
            string opp;
            string running;
            int a;
            cin>>opp;

            if(opp == "ADD"){
                cin>>a;
                if(currFunc == ""){
                    ans += a;
                    ans %= mod;
                } else {
                    funcs.at(currFunc).push_back(make_pair('a', a));
                }
            } else if(opp == "MULT"){
                cin>>a;
                if(currFunc == ""){
                    ans *= a;
                    ans %= mod;
                } else {
                    funcs.at(currFunc).push_back(make_pair('m', a));
                }
            } else if(opp == "SUB"){
                cin>>a;
                if(currFunc == ""){
                    ans -= a;
                    ans %= mod;
                } else {
                    funcs.at(currFunc).push_back(make_pair('s', a));
                }
            }
        }

        cout<<ans % mod <<'\n';
    }
}
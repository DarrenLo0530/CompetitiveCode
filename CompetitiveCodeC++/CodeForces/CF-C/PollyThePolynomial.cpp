#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    string s, t;

    while(getline(cin, s) && getline(cin, t)){
        vector<int> co;
        vector<int> tests;
        stringstream in(s);
        int a;
        while(in >> a){
            co.push_back(a);
        }

        stringstream in2(t);
        while(in2 >> a){
            tests.push_back(a);
        }

        for(int i = 0; i<tests.size(); i++){
            ll ans = 0;
            for(int j: co){
                ans *= tests[i];
                ans += j;
            }

            if(i != 0){
                cout<<" ";
            }

            cout<<ans;
        }

        cout<<'\n';
    }
}
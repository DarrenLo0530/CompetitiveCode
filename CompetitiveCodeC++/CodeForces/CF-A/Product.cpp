#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    string a, b;
    while(cin>>a){
        cin>>b;

        int ans[1000];
        memset(ans, 0, sizeof(ans));
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        for(int i = 0; i<a.size(); i++){
            for(int j = 0; j<b.size(); j++){
                ans[i+j] += (a[i] - '0') * (b[j] - '0');
            }
        }

        for(int i = 0; i<999; i++){
            ans[i+1] += ans[i]/10;
            ans[i] %= 10;
        }

        int counter = 999;
        while(counter > 0 && ans[counter] == 0){
            counter--;
        }
        for(int i = counter; i>=0; --i){
            cout<<ans[i];
        }
        cout<<'\n';
        
    }
}
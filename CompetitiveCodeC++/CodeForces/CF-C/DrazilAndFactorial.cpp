#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> ans;
    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        int x;
        scanf("%1d", &x);
        if(x == 4){
            ans.push_back(2);
            ans.push_back(2);
            ans.push_back(3);
        } else if(x == 6){
            ans.push_back(5);
            ans.push_back(3);
        } else if(x == 8){
            ans.push_back(2);
            ans.push_back(2);
            ans.push_back(2);
            ans.push_back(7);
        } else if(x == 9){
            ans.push_back(7);
            ans.push_back(3);
            ans.push_back(3);
            ans.push_back(2);

        } else if(x != 0 && x != 1){
            ans.push_back(x);
        }
    }

    sort(ans.begin(), ans.end(), greater<int>());    

    for(int i : ans){
        cout<<i;
    }

    cout<<'\n';

}
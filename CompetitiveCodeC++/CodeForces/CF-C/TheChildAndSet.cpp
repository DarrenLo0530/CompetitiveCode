#include <bits/stdc++.h>
using namespace std;
int main(){
    int sum, limit;
    scanf("%d%d", &sum, &limit);
    
    vector<int> ans;
    for(int i = limit; i>=1 ; i--){
        if(sum - (i & -i) >= 0){
            sum -= (i & -i);
            ans.push_back(i);
        }
    }

    if(sum == 0){
        cout<<ans.size()<<'\n';
        for(int i =0; i<ans.size(); i++){
            if(i != 0){
                cout<<" ";
            }

            cout<<ans[i];
        }
    } else {
        cout<<"-1";
    }

    cout<<'\n';
}
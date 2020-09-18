#include <bits/stdc++.h>
using namespace std;
int ans[200001];
bool used[200001];

int main(){
    int n;
    scanf("%d", &n);
    if(n % 2 == 0){
        cout<<"NO\n";
        return 0;
    }

    cout<<"YES\n";
    int add = true;
    int curr = 1;
    for(int i = 0; i<n; i++){
        if(add){
            ans[i] = curr;
            ans[i + n] = curr+1;
            curr+=2;
        } else {
            ans[i] = curr + 1;
            ans[i+n] = curr;
            curr+=2;
        }

        add = !add;
    }

    for(int i = 0; i<2*n; i++){
        if(i != 0){
            cout<<" ";
        }
        cout<<ans[i];
    }
}
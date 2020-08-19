#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    vector<int> knights;
    for(int i = 0; i<n; i++){
        int x;
        scanf("%d", &x);
        knights.push_back(x);
    }

    for(int i = 1; i<=n/3; i++){
        if(n % i != 0){
            continue;
        }

        for(int start = 0; start < i; start++){
            bool suc = true;
            for(int curr = start; curr < n; curr += i){
                if(knights[curr] == 0){
                    suc = false;
                }
            }

            if(suc){
                cout<<"YES"<<'\n';
                return 0;
            }
        }
    }

    cout<<"NO"<<'\n';

    
}
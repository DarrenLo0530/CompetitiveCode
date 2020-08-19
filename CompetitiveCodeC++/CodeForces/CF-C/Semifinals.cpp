#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> total;
int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0;i<n; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        total.push_back({a, 0});
        total.push_back({b, 1});
    }

    sort(total.begin(), total.end());

    int a = 0, b = 0;
    for(int i = 0; i<n; i++){
        if(total[i].second == 0){
            a++;
        } else {
            b++;    
        }
    }
    for(int i = 0; i<n; i++){
        if(a > 0 || i < n/2){
            cout<<1;
        } else {
            cout<<0;
        }
        a--;
    }

    cout<<'\n';
    for(int i = 0; i<n; i++){
        if(b > 0 || i < n/2){   
            cout<<1;
        } else {
            cout<<0;
        }
        b--;
    }
    cout<<'\n';
}
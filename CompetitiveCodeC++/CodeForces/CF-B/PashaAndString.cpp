#include <bits/stdc++.h>
using namespace std;

int idx[200005];

int main(){
    string s;
    cin >> s;
    int m;
    scanf("%d", &m);

    for(int i = 0; i<m; i++){
        int x;
        scanf("%d", &x);
        idx[x]++;
    }

    for(int i = 1; i<=s.size()/2; i++){
        idx[i] += idx[i-1];
        if(idx[i] % 2 != 0){
            swap(s[i-1], s[s.size() - i]);
        }
    }

    cout<<s;

}
#include <bits/stdc++.h>
using namespace std;
int np[1000001];
int st[1000001], nd[1000001];

int main(){
    int n;
    set<int> nums;
    vector<int> ans;
    scanf("%d",  &n);
    for(int i = 0; i<n; i++){
        int first, last;
        scanf("%d%d", &first, &last);
        np[first] = last;
        st[first] = true;
        nd[last] = true;
    }

    int start1, start2 = np[0];
    for(int i = 0; i<1000001; i++){
        if(st[i] && !nd[i]){
            start1 = i;
        }
    }

    for(int i = 0; i<n; i++){
        if(i != 0){
            cout<<" ";
        }
        if(i % 2 == 0){
            cout<<start1;
            start1 = np[start1];
        } else {
            cout<<start2;
            start2 = np[start2];
        }
    }

    cout<<'\n';
}
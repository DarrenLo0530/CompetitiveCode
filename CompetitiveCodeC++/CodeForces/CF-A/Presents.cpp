#include <bits/stdc++.h>
using namespace std;

int friends[101];

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 1; i<=n; i++){
        int x;
        scanf("%d", &x);
        friends[x] = i;
    }

    for(int i = 1; i<=n; i++){
        cout<<friends[i] << " ";
    }
}
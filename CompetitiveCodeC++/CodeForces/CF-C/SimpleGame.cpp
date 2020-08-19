#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    if(n == 1){
        cout<<1<<'\n';
        return 0;
    }
    
    int left = m -1;
    int right = n - m;
    if(left >= right){
        cout<<m-1<<'\n';
    } else {
        cout<<m+1<<"\n";
    }
}
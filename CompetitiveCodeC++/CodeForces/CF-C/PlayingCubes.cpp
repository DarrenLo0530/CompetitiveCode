#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int total = n + m -1;
    int ans2 = min(n, m);
    int ans1 = total - ans2;
    cout<<ans1<<" "<<ans2<<'\n';
}


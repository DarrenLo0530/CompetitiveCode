#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> sides;
    for(int i = 0; i<6; i++){
        int x;
        scanf("%d", &x);
        sides.push_back(x);
    }

    int base = pow(sides[0] + sides[1] + sides[2], 2);
    int ans = base - sides[0]*sides[0] - sides[2]*sides[2] - sides[4]*sides[4];
    cout<<ans<<'\n';



}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int g = 0;
    int mx = 0;
    for(int i = 0; i<n; i++){
        int a;
        scanf("%d", &a);
        g = __gcd(g, a);
        mx = max(mx, a);
        //Count number of possible moves
        //Same number of moves possible no matter what order
    }

    int ans = mx/g - n;
    if(ans % 2 != 0){
        printf("Alice\n");
    } else {
        printf("Bob\n");
    }
}
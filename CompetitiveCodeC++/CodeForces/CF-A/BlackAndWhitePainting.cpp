#include <bits/stdc++.h>
using namespace std;

int getNumWhite(int n, int m, int c){
    if(n <= 0 || m <= 0){
        return 0;
    }

    if(c == 0){
        return n*m/2;
    } else {
        return n*m - n*m/2;
    }
}

int main(){
    while(true){
        int n, m, c;
        scanf("%d%d%d", &n, &m, &c);
        if(n == 0 && m == 0){
            break;
        }
        
        n-=7;
        m-=7;

        int ans = getNumWhite(n, m, c);
        cout << ans << '\n';        
    }
}

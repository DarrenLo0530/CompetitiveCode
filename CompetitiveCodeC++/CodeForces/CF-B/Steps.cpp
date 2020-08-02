#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, x, y;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    n--;
    m--;
    x--;
    y--;

    int k;
    scanf("%d", &k);

    long long steps = 0;
    while(k--){
        int dx, dy;
        scanf("%d%d", &dx, &dy);

        int addSteps = 0x3f3f3f3f;
        if(dx < 0){
            addSteps = abs(x/dx);
        } else if(dx != 0) {
            addSteps = (n - x)/dx;
        }
        
        if(dy < 0){
            addSteps = min(abs(y/dy), addSteps);
        } else if(dy != 0) {
            addSteps = min((m - y)/dy, addSteps);
        }

        x += addSteps * dx;
        y += addSteps * dy;
        steps += addSteps;
    }

    printf("%lld\n", steps);
}
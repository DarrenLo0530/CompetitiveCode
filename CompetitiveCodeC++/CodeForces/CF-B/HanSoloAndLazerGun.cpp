#include <bits/stdc++.h>
using namespace std;


set<pair<int, int>> ans;
pair<int, int> slope(int x, int y, int x2, int y2){
    if(x2 - x == 0){
        return {0x3f3f3f3f, 0};
    } else if(y2 - y == 0){
        return {0, 0x3f3f3f3f};
    } else {
        int changeX = x - x2;
        int changeY = y - y2;
        int divisor = __gcd(abs(changeX), abs(changeY));
        changeY /= divisor;
        changeX /= divisor;
        if(changeY < 0 && changeX < 0){
            return {abs(changeY), abs(changeX)};
        } else if(changeY > 0 && changeX < 0){
            return {changeY * -1, changeX * -1};
        }


        return {changeY, changeX};
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int x0, y0;
    scanf("%d%d", &x0, &y0);

    for(int i = 0; i<n; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        ans.insert(slope(x, y, x0, y0));
    }


    printf("%d\n", ans.size());

}
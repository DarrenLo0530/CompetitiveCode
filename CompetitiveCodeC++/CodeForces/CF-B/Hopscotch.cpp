#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, x, y;
    scanf("%d%d%d",&a,&x, &y);
    
    if(y % a == 0){
        printf("-1\n");
        return 0;
    }

    int column = y/a + 1;
    if(column % 2 == 0 || column == 1){
        if(abs(x) >= (double)a/2){
            printf("-1\n");
            return 0;
        }
    } else {
        if(x == 0 || abs(x) >= a){
            printf("-1\n");
            return 0;
        }
    }

    int squareNumber = 1 + (column - 2)/2 * 3;
    if(column == 1){
        squareNumber = 1;
    } else if(column % 2 == 0){
        squareNumber++;
    } else if(x > 0){
        squareNumber+=3;
    } else {
        squareNumber += 2;
    }
    printf("%d\n", squareNumber);
}
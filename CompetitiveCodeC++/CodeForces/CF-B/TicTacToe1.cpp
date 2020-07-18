#include <bits/stdc++.h>
using namespace std;

char grid[3][3];

bool isWin(char p){
    string s = "";
    s += p + p + p;

    //Horizontal
    for(int i = 0; i<3; i++){
        string check = "";
        check += grid[i][0] + grid[i][1] + grid[i][2];
        if(check == s){
            return true;
        }
    }

    //Vertical
    for(int i = 0; i<3; i++){
        string check = "";
        check += grid[0][i] + grid[1][i] + grid[2][i];
        if(check == s){
            return true;
        }
    }

    string check2 = "";
    check2 += grid[0][0] + grid[1][1] + grid[2][2];
    string check3 = "";
    check3 += grid[0][2] + grid[1][1] + grid[2][0];

    return check2 == s || check3 == s;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int xCount = 0;
        int oCount = 0;
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                scanf(" %c", &grid[i][j]);
                if(grid[i][j] == 'X'){
                    xCount++;
                } else if(grid[i][j] == 'O'){
                    oCount++;
                }
            }
        }

        if(isWin('X') && isWin('O') || oCount > xCount || xCount >= oCount + 2){
            printf("no\n");
        } else if(isWin('X') && oCount != xCount-1){
            printf("no\n");
        } else if(isWin('O') && xCount != oCount){
            printf("no\n");
        } else {
            printf("yes\n");
        }
    }
}
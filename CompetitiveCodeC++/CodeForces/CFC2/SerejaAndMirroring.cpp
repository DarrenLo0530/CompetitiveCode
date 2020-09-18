#include <bits/stdc++.h>
using namespace std;
set<int> twoPow;
int r, c;
int grid[101][101];

int symmetry(int h){
    if(h % 2 != 0){
        return h;
    }

    bool isSymmetry = true;
    for(int i = 1; i<=h/2; i++){
        for(int j = 1; j<=c; j++){
            if(grid[i][j] != grid[h-i+1][j]){
                isSymmetry = false;
            }
        }
    }

    if(isSymmetry){
        return symmetry(h/2);
    } else {
        return h;
    }
    
}

int main(){
    scanf("%d%d", &r, &c);
    for(int i = 1; i<=r; i++){
        for(int j = 1; j<=c; j++){
            scanf("%d", &grid[i][j]);
        }
    }

    printf("%d\n", symmetry(r));
}
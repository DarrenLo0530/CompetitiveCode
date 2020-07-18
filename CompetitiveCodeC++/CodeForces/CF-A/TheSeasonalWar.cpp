#include <bits/stdc++.h>
using namespace std;

int n;
int grid[26][26];
int movement[8][2] = {{1, 1}, {-1, -1}, {-1, 1}, {1, -1}, {0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void findNext(int y, int x){
    for(int i = 0; i<8; i++){
        int nextX = x + movement[i][0];
        int nextY = y + movement[i][1];

        if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < n && grid[nextY][nextX]){
            grid[nextY][nextX] = 0;
            findNext(nextY, nextX);
        }
    }
}


int main(){
    int imageno = 1;
    while(cin >> n){
        memset(grid, 0, sizeof(grid));
        int ans = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                scanf("%1d", &grid[i][j]);       
            }
        }


        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]){
                    grid[i][j] = 0;
                    findNext(i, j);
                    ++ans;
                }
            }
        }

        printf("Image number %d contains %d war eagles.\n", imageno, ans);
        ++imageno;
    }
    
}
#include <bits/stdc++.h>
using namespace std;

int n, r, c, pr, pc, kr, kc;
int visited[102][102];
int movement[8][2] = { {2, 1}, {2, -1}, {1, -2}, {1, 2}, {-2, -1}, {-2, 1}, {-1, 2}, {-1, -2}};


pair<int, int> traverse(){
    memset(visited, -1, sizeof(visited));

    if(pr == r){
        return make_pair(0, 2);
    }

    int staleMate = 200;
    int turn = 1;
    visited[kr][kc] = 0;

    while(pr < r){
        pr++;
        if(visited[pr][pc] == turn - 1){
            staleMate = min(turn - 1, staleMate);
            visited[pr][pc] = -1;
        }


        if(pr == r){
            break;
        }
        
        for(int i = 1; i<=r; i++){
            for(int j = 1; j<=c; j++){
                if(visited[i][j] == turn - 1){
                    for(int m = 0; m<8; m++){
                        int newX = j + movement[m][0];
                        int newY = i + movement[m][1];
                        if(newY == pr && newX == pc){
                            return make_pair(turn, 1);
                        }
                        if(newX >= 1 && newX <= c && newY >= 1 && newY <= r){
                            visited[newY][newX] = turn;
                        }
                    }
                }
            }
        }

        turn++;
    }
    
    if(staleMate == 200){
        return make_pair(-1, 2);
    } else {
        return make_pair(staleMate, 3);
    }
}

int main(){
    cin>>n;

    for(int i = 0; i<n; i++){
        cin>>r>>c>>pr>>pc>>kr>>kc;  
        int t = pr;

        auto ret = traverse(); 
        if(ret.second == 1){
            printf("Win in %d knight move(s).\n", ret.first);
        } else if(ret.second == 2){
            printf("Loss in %d knight move(s).\n", r - t - 1);
        } else {
            printf("Stalemate in %d knight move(s).\n", ret.first);
        }
    }   
}
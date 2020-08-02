#include <bits/stdc++.h>
using namespace std;

char sym[2] = {'X', 'O'};
string endBoard;
set<string> visited;
set<string> good;
queue<pair<string, int>> allBoard;


bool isOver(string board){
    for(char x: sym){
        for(int i = 0, j = 0; i<9, j < 3; i+=3, j++){
            if(board[i] == x && board[i+1] == x && board[i+2] == x){
                return true;
            }
            if(board[j] == x && board[j+3] == x && board[j+6] == x){
                return true;
            }
        }

        if(board[0] == x && board[4] == x && board[8] == x){
            return true;
        }
        if(board[2] == x && board[4] ==x && board[6] == x){
            return true;
        }
    }

    for(int i = 0; i<9; i++){
        if(board[i] == '.'){
            return false;
        }
    }

    return true;
}

void generate(){
    string board = ".........";
    allBoard.push({board, 0});

    while(!allBoard.empty()){
        string board = allBoard.front().first;
        int turn = allBoard.front().second;
        allBoard.pop();

        if(isOver(board)){
            good.insert(board);
            continue;
        }

        for(int i = 0; i<9; i++){
            if(board[i] == '.'){
                string copy = board;
                copy[i] = sym[turn];
                if(visited.count(copy)){
                    continue;
                }

                visited.insert(copy);
                allBoard.push({copy, turn ^ 1});
            }
        }
    }
}

int main(){
    generate();


    while(true){
        cin >> endBoard;
        if(endBoard == "end"){
            return 0;
        }

        if(good.count(endBoard)){
            printf("valid\n");
        } else {
            printf("invalid\n");
        }

    }
    
}
#include <bits/stdc++.h>
using namespace std;
int T, G;

int getPossibilities(vector<int> gameState, vector<vector<bool>> matches){
    int ans = 0;
    bool gameFound = false;
    //Find game
    int teamA = 0, teamB = 0;
    for(int i = 1; i<=4 && !gameFound; i++){
        for(int j = 1; j<=4 && !gameFound; j++){
            if(matches[i][j]){
                teamA = i, teamB = j;
                matches[i][j] = matches[j][i] = false;
                gameFound = true;
            }
        }
    }

    if(!gameFound){//Base case there are no games left to play!
        int teamScore = gameState[T];
        for(int i = 1; i<=4; i++){
            if(gameState[i] >= teamScore && i!=T){
                return 0;//Team is not victor
            }
        }
        return 1;
    }
    //Else go through all possibilities of the current game, run getPossibilities again to play the next game;
    //Case team A wins
    vector<int> aWin = gameState;
    aWin[teamA] += 3;
    ans += getPossibilities(aWin, matches);

    //Case team B wins
    vector<int> bWin = gameState;
    bWin[teamB] += 3;
    ans += getPossibilities(bWin, matches);

    //Case tie
    vector<int> tie = gameState;
    tie[teamA] += 1, tie[teamB] += 1;
    ans += getPossibilities(tie, matches);

    return ans;
}
int main(){
    int A, B, SA, SB;
    scanf("%d %d", &T, &G);
    vector<int> pts(5);
    vector<vector<bool>> matches(5, vector<bool>(5, true));

    for(int i = 0; i<=4; i++){
        matches[i][i] = false;
    }

    for(int i = 0; i<G; i++){
        scanf("%d %d %d %d", &A, &B, &SA, &SB);
        matches[A][B] = false;
        matches[B][A] = false;
        if(SA > SB){
            pts[A] += 3;
        } else if(SA < SB){
            pts[B] += 3;
        } else {
            ++pts[A], ++pts[B];
        }
    }
    
    cout<< getPossibilities(pts, matches);
}
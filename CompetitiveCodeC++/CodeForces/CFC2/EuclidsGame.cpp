#include <bits/stdc++.h>
using namespace std;

bool dfs(int a, int b, int turn){
    if(!a || !b){
        if(turn == 1){
            return true;
        } else {
            return false;
        }
    }
    if(a > b){
        swap(a, b);
    }
    
    if(b/a == 1){
        return dfs(b%a, a, 1-turn);
    } else {
        if(turn == 0){
            return dfs(b%a, a, 1-turn) || dfs(b%a, a, turn);
        } else {
            return dfs(b%a, a, 1-turn) && dfs(b%a, a, turn);
        }
    }
}

int dfs2(int a, int b, int turn){
    if(a > b){
        swap(a, b);
    }

    if(a == 0 || b == 0){
        return 1-turn;
    }

    if(b/a > 1){
        return turn;
    }

    return dfs2(a, b-a, 1-turn);
}

int main(){
    while(true){
        int a, b;
        scanf("%d%d", &a, &b);
        if(!a && !b){
            break;
        }

        if(!dfs2(a, b, 0)){
            printf("Stan wins\n");
        } else {
            printf("Ollie wins\n");
        }
    }

    //If a is a multiple of b, then current player wins
    //If a is not a multiple of b, then 
}

//a-xb
//
#include <bits/stdc++.h>

using namespace std;
int table[101][101];
int N;

bool Ass(){//
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            for(int k = 1; k<=N; k++){
                if(table[table[i][j]][k] != table[i][table[j][k]]){
                    return false;
                }
            }
        }
    }

    return true;
}
int Ide(){//n^2
    for(int i =1; i<=N; i++){//Checking if i is identity
        bool isIde = true;
        for(int j = 1; j<=N; j++){
            isIde = isIde && (table[i][j] == j && table[j][i] == j);
        }

        if(isIde){
            return i;
        }
    }
    return 0;

}
bool Inv(int identity){
    bool allInv = true;
    for(int i = 1; i<=N; i++){
        bool hasInverse = false;
        for(int j = 1; j<=N; j++){
            if(table[i][j] == identity && table[j][i] == identity){
                hasInverse = true;
            }
        }
        allInv = hasInverse && allInv;
    }

    return allInv;

}
bool isGroup(){
    int identity = Ide();
    if(identity){
        return Inv(identity) && Ass();

    }
    return false;
}

int main(){
    while(true){
        scanf("%d", &N);
        if(!N){
            break;
        }

        memset(table, 0, sizeof(table));

        for(int i = 1; i<=N; i++){
            for(int j = 1; j<=N; j++){
                scanf("%d", &table[i][j]);
            }
        }

        if(isGroup()){
            cout<<"yes"<<"\n";
        } else {
            cout<<"no"<<"\n";
        }
    }
}
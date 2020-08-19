#include <bits/stdc++.h>
using namespace std;

bool tried[8][8];
bool grid[8][8];
int x, y;

int attacked[8][8];
vector<vector<int>> answers;

bool inBounds(int x){
    return x >= 0 && x < 8;
}
void updateAttacked(int x, int y, int updateNum){
    int temp = attacked[y][x];
    for(int i = 0; i<8; i++){
        attacked[y][i] += updateNum;
        attacked[i][x] += updateNum;
    }

    for(int i = -8; i<=8; i++){
        if(inBounds(x + i) && inBounds(y - i)){
            attacked[y-i][x+i] += updateNum;
        }

        if(inBounds(x + i) && inBounds(y + i)){
            attacked[y + i][x + i] += updateNum;
        }
    }

    attacked[y][x] = temp + updateNum;
}

void generateAll(int col){
    if(col == x){
        generateAll(col + 1);
    }

    if(col > 7){
        vector<int> newAns;
        for(int i = 0; i<8; i++){
            for(int j = 0; j<8; j++){
                if(grid[j][i]){
                    newAns.push_back(++j);
                }
            }
        }

        answers.push_back(newAns);
        return;
    }

    for(int i = 0; i<8; i++){
        if(!attacked[i][col]){
            updateAttacked(col, i, 1);
            grid[i][col] = true;
            generateAll(col + 1);
            
            updateAttacked(col, i, -1);
            grid[i][col] = false;
        }
        
    }
}

int main(){
    int t;
    scanf("%d", &t);

    for(int z = 0; z<t; z++){
        if(z != 0){
            cout<<'\n';
        }
        cout<<"SOLN       COLUMN\n";
        cout<<" #      1 2 3 4 5 6 7 8\n\n";
        answers.clear();
        memset(tried, false, sizeof(tried));
        memset(grid, false, sizeof(grid));
        memset(attacked, 0, sizeof(attacked));


        scanf("%d%d", &y, &x);
        x--, y--;

        grid[y][x] = true;
        updateAttacked(x, y, 1);

        /*
        for(int i = 0; i<8; i++){
            for(int j = 0; j<8; j++){
                cout<<grid[i][j]<<" ";
            }

            cout<<'\n';
        }
        */
        
        generateAll(0);

        for(int i = 0; i<answers.size(); i++){
            printf("%2d", i + 1);
            cout<<"     ";
            for(int j = 0; j<answers[i].size(); j++){
                cout<<" ";
                cout<<answers[i][j];
            }
            cout<<'\n';
        }
    
    }
    
}
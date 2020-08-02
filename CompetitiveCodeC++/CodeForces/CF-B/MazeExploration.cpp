#include <bits/stdc++.h>
using namespace std;

int length[100];
char maze[100][100];
int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(int x, int y){
    maze[y][x] = '#';

    for(int i = 0; i<4; i++){
        int newX = x + moves[i][0];
        int newY = y + moves[i][1];
        if(newX >= 0 && newY >= 0 && maze[newY][newX] == ' '){
            dfs(newX, newY);
        }
    }
}
int main(){
    int n;
    scanf("%d ", &n);
    for(int f = 0; f<n; f++){
        string breaks;
        memset(length, 0, sizeof(length));
        memset(maze, ' ', sizeof(maze));
        int startX, startY;

        for(int y = 0; ; y++){
            string nextLine;
            getline(cin, nextLine);

            if(nextLine.find('_') != string::npos){
                breaks = nextLine;
                break;
            }

            length[y] = nextLine.size();
            for(int i = 0; i<nextLine.size(); i++){
                maze[y][i] = nextLine[i];
                if(maze[y][i] == '*'){
                    startY = y;
                    startX = i;
                }
            }
        }
        dfs(startX, startY);
        for(int i = 0; i<100; i++){
            if(length[i] <= 0){
                break;
            }

            for(int j = 0; j<length[i]; j++){
                cout<<maze[i][j];
            }

            cout<<'\n';
        }

        cout<<breaks<<'\n';

    }
    
}
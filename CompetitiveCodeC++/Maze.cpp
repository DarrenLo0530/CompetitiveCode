#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int t, r, c;
char grid[25][25];
bool v[25][25];
int movement[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};


int getMinDist(){
    queue<pi> tv;
    v[1][1] = true;
    tv.push(make_pair(1, 1));
    int counter = 1;
    
    while(!tv.empty()){
        queue<pi> nextTv;

        while(!tv.empty()){
            int l, ri;
            pi curr = tv.front();
            tv.pop();

            char inter = grid[curr.second][curr.first];

            if(curr.first == c && curr.second == r){
                return counter;
            }

            if(inter == '*'){
                continue;
            }
            else if(inter == '+'){ 
                l = 0; ri = 4;
            } else if(inter == '-'){
                l = 2; ri = 4;
            } else {
                l = 0; ri = 2;
            }

            for(int i = l; i<ri; i++){
                int newX = movement[i][0] + curr.first;
                int newY = movement[i][1] + curr.second;
                if(!v[newY][newX]){
                    v[newY][newX] = true;
                    nextTv.push(make_pair(newX, newY));
                }
            }
        }

        tv = nextTv;
        counter++;
    }
    return -1;
}

int main(){
    scanf("%d", &t);

    for(int i = 0; i<t; i++){
        scanf("%d %d", &r, &c);

        memset(grid, '*', sizeof(grid));
        memset(v, false, sizeof(v));


        for(int i = 1; i<=r; i++){
            for(int j = 1; j<=c; j++){
                cin>>grid[i][j];
            }
        } 

        if(grid[r][c] == '*'){
            cout<<-1<<"\n";
        } else {
            cout<<getMinDist()<<"\n";
        }    
    }


}
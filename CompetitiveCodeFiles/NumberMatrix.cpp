#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int N, M;

//N Rows

bool tried[2000];
int directions[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int grid[110][110];
bool v[110][110];


int getHash(set<int> &nums){
    int hsh = 0;
    int cnt = 0;

    for(auto it = nums.begin(); it != nums.end(); ++it){
        hsh += *it * pow(11, cnt);
        cnt++;
    }
    return hsh;
}


bool traverse(set<int> &nums){
    memset(v, false, sizeof(v));
    memset(v[0], true, sizeof(v[0]));

    queue<pi> tv;
    for(int i = 1; i<=N; i++){
        tv.push(pi{i, 0});
    }    

    while(!tv.empty()){
        pi curr = tv.front();
        tv.pop();
        int y = curr.second, x = curr.first;

        if(y == M){
            return true;
        }

        for(int i = 0; i<4; i++){
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];
            if(newY >= 0 && !v[newY][newX] && count(nums.begin(), nums.end(), grid[newY][newX])){
                v[newY][newX] = true;
                tv.push(pi{newX, newY});
            }
        }
    }

    return false;
}

int main(){
    scanf("%d %d", &N, &M);
    memset(grid, -1, sizeof(grid));

    for(int i = 1; i<=M; i++){
        for(int j = 1; j<=N; j++){
            scanf("%d", &grid[i][j]);
        }
    }

    for(int i = 0; i<10; i++){ //first
        for(int j = 0; j<10; j++){ //second last
            for(int k = 0; k<10; k++){//Last number
                set<int> nums {i, j, k};

                int hsh = getHash(nums);
                if(!tried[hsh]){
                    tried[hsh] = true;
                    if(traverse(nums)){
                        printf("%d %d %d", i, j, k);
                        return 0;
                    }
                }
            }
        }
    }

    printf("%d %d %d", -1, -1, -1);

}

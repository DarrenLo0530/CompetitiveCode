#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int ans[3][3];

void fillDouble(){
    bool filled;
    do { 
        filled = false;
        for(int i = 0; i<3; i++){
            int cnt = 0;
            int idx = 0;
            for(int j = 0; j<3; j++){
                if(ans[i][j] != INF){
                    cnt++;
                } else {
                    idx = j;
                }
            }

            if(cnt == 2){
                filled = true;
                if(idx == 0){
                    ans[i][idx] = ans[i][1] - (ans[i][2] - ans[i][1]);
                } else if(idx == 1){
                    ans[i][idx] = ans[i][0] + (ans[i][2] - ans[i][0])/2;
                } else {
                    ans[i][idx] = ans[i][1] + ans[i][1] - ans[i][0];
                }
            }
        }

        for(int i = 0; i<3; i++){
            int cnt = 0;
            int idx = 0;
            for(int j = 0; j<3; j++){
                if(ans[j][i] != INF){
                    cnt++;
                } else {
                    idx = j;
                }
            }

            if(cnt == 2){
                filled = true;
                if(idx == 0){
                    ans[idx][i] = ans[1][i] - (ans[2][i] - ans[1][i]);
                } else if(idx == 1){
                    ans[idx][i] = ans[0][i] + (ans[2][i] - ans[0][i])/2;
                } else {
                    ans[idx][i] = ans[1][i] + ans[1][i] - ans[0][i];
                }
            }
        }
    } while(filled);
}

int used(){
    int cnt = 0;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(ans[i][j] != INF){
                cnt++;
            }
        }
    }

    return cnt;
}

bool isValid(){
    for(int i = 0; i<3; i++){
        if(ans[i][2] - ans[i][1] != ans[i][1] - ans[i][0]){
            return false;
        }

        if(ans[2][i] - ans[1][i] != ans[1][i] - ans[0][i]){
            return false;
        }
    }

    return true;
}

void solve(){
    int cnt = used();
    fillDouble();

    if(cnt == 0){
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                ans[i][j] = 1;
            }
        }
    } else if(cnt == 1){
        int num = INF;
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                num = min(num, ans[i][j]);
            }
        }
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
            
                ans[i][j] = num;
            }
        }
    } else if(cnt >= 2 && cnt <= 5){        
        int sqr[9][2] = {{1, 1}, {2, 1}, {1, 0}, {0, 1}, {1, 2}, {0, 0}, {0, 2}, {2, 2}, {2, 0}};
        for(int i = 0; i<9 && !isValid(); i++){
            if(ans[sqr[i][0]][sqr[i][1]] != INF){
                continue;
            }
            ans[sqr[i][0]][sqr[i][1]] = 0;
            fillDouble();
        }
    }
}

int main(){
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            string s;
            cin >> s;
            if(s == "X"){
                ans[i][j] = INF;
            } else {
                ans[i][j] = stoi(s);
            }
        }
    }
    solve();
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(j != 0){
                printf(" ");
            }
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
}
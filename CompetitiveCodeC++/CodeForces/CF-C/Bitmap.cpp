#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

int n, m;
int bitmap[200][200];
int ans[200][200];
int movement[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        memset(ans, INF, sizeof(ans));


        scanf("%d%d", &n, &m);

        queue<pair<pair<int, int>, int>> tv;

        for(int i = 0;i<n; i++){
            for(int j = 0; j<m; j++){
                scanf("%1d", &bitmap[i][j]);
                if(bitmap[i][j] == 1){
                    tv.push({{j, i}, 0});
                }
            }
        }

        while(!tv.empty()){
            auto next = tv.front();
            tv.pop();

            if( ans[next.first.second][next.first.first] != INF){
                continue;
            }
            
            ans[next.first.second][next.first.first] = next.second;

            for(int i = 0; i<4; i++){
                int newX = next.first.first + movement[i][0];
                int newY = next.first.second + movement[i][1];
                if(newY >= 0 && newY < n && newX >= 0 && newX < m){
                    tv.push({{newX, newY}, next.second + 1});
                }
            }            
        }

        for(int i = 0; i<n; i++){
            for(int j = 0 ; j<m; j++){
                if(j != 0){
                    cout<<" ";
                }

                cout<<ans[i][j];
            }

            cout<<"\n";
        }

        
    }
}
#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;


int n, h;
int d[30], t[30], f[30];
int fish[30][200];
pair<int, vector<int>> dp[30][200];

int compare(pair<int, vector<int>> &a1, pair<int, vector<int>> &a2){
    if(a1.first <= -1){
        return 2;
    }

    if(a1.first > a2.first){
        return 1;
    } else if(a2.first > a1.first){
        return 2;
    } else {
        for(int i = 0; i<min(a1.second.size(), a2.second.size()); i++){
            if(a1.second[i] > a2.second[i]){
                return 1;
            } else if(a2.second[i] > a1.second[i]){
                return 2;
            }
        }
    }

    return 1;
}

pair<int, vector<int>> solve(int lake, int time){
    if(time < 0){
        return dp[29][199];
    }

    if(dp[lake][time].first != -1){
        return dp[lake][time];
    }


    if(lake <= 1){
        pair<int, vector<int>> copy = dp[29][199];
        copy.first = fish[lake][time];
        copy.second.push_back(time);
        return copy;
    }

    for(int i = 0; i<=time; i++){
        pair<int, vector<int>> prev;
        if(time == h && i == 0){
            prev = solve(lake-1, time);
        } else {
            prev = solve(lake-1, time - i - t[lake-1]);
        }

        if(prev.first >= 0){
            prev.first += fish[lake][i];
            prev.second.push_back(i);
            if(compare(dp[lake][time], prev) == 2){
                dp[lake][time] = prev;
            }
        } else {
            break;
        }
    }

    return dp[lake][time];
}

int main(){
    int cnt = 0;
    while(cin >> n){
        if(!n){
            break;
        }
        cin >> h;
        h*=12;

        for(int i = 0; i<30; i++){
            for(int j = 0; j<200; j++){
                dp[i][j].first = -1;
                dp[i][j].second.clear();
            }
        }

        for(int i = 1; i<=n; i++){
            scanf("%d", f + i);
        }
        for(int i = 1; i<=n; i++){
            scanf("%d", d + i);
        }
        for(int i = 1; i<=n-1; i++){
            scanf("%d", t + i);
        }
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=h; j++){
                if(j == 1){
                    fish[i][j] = f[i];
                } else {
                    fish[i][j] = fish[i][j-1] + max(0, f[i] - d[i]*(j-1));
                }
            }
        }


        if(cnt++ != 0){
            printf("\n");
        }
        pair<int, vector<int>> ans = solve(n, h);
        for(int i = 0; i<ans.second.size(); i++){
            if(i != 0){
                printf(", ");
            }
            printf("%d", ans.second[i] * 5);
        }
        printf("\nNumber of fish expected: %d\n", ans.first);
    }
}
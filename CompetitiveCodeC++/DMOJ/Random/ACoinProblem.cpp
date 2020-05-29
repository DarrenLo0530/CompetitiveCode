#include <iostream>
using namespace std;

int main() {
	int n, v;
	scanf("%d %d", &n, &v);
	int coins [n+1];

	for(int i = 0; i < n; i++){
		scanf("%d", &coins[i+1]);
	}

	short cValues [v];
	short jValues [v];
	short ans [v];
	int c = 0;
	int j = 0;

	for(int i = 0; i<v; i++){
        scanf("%hd %hd", &cValues[i], &jValues[i]);

		if(cValues[i] > c){
            c = cValues[i];
		}
		if(jValues[i] > j){
            j = jValues[i];
		}
    }

    int dp[c+1];
    fill(dp, dp+c+1, -1);
    dp[0] = 0;

    for(int y = 1; y<j+1; y++){
        for(int x = 0; x<c+1; x++){
            if(x+coins[y] < c+1){
                if(dp[x] != -1 && ((dp[x + coins[y]] == -1) || dp[x + coins[y]] > dp[x] + 1)){
                    dp[x + coins[y]] = dp[x] + 1;
                }
            }
        }
        for(int i = 0; i<v; i++){
            if(jValues[i] == y){
                ans[i] = dp[cValues[i]];
            }
        }
    }

    for(int i = 0; i<v; i++){
        printf("%d\n", ans[i]);
    }


}

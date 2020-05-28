#include <bits/stdc++.h>
using namespace std;
int num[4];
int N, f;
double dp[301][301][301];
//dp[a][b][c] = Expected number of operations to finish sushi 'a' plates of 1, 'b' plates of 2...

double dpUtil(int n1, int n2, int n3){
    if(n1 == 0 && n2 == 0 && n3 == 0){
        return 0;
    } else if(dp[n1][n2][n3] != 0){
        return dp[n1][n2][n3];
    }
    
    //Expected number of operations to eat one sushi in curr turn
    double expectedOperations = (double) N / (n1 + n2 + n3);
    //Eat plate with 1 sushi
    expectedOperations += (n1 > 0) ? (double) n1/(n1 + n2 + n3) * dpUtil(n1 - 1, n2, n3): 0;
    expectedOperations += (n2 > 0) ? (double) n2/(n1 + n2 + n3) * dpUtil(n1 + 1, n2 - 1, n3): 0;
    expectedOperations += (n3 > 0) ? (double) n3/(n1 + n2 + n3) * dpUtil(n1, n2 + 1, n3 - 1): 0;
    dp[n1][n2][n3] = expectedOperations;


    return expectedOperations;
}

int main(){
    cin>>N;

    for(int i = 0; i<N; i++){
        cin>>f;
        num[f]++;
    }

    double e = dpUtil(num[1], num[2], num[3]);
    printf("%.11f", e);
}
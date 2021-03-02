#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;


int distances[201][201];
int dp[201][31];
int d[201];
int first[201][201];

int n, k;
int c = 0;

void printHouses(int e, int h){
    if(h == 0){
        return;
    }
    int s = first[e][h];
    printHouses(s-1, h-1);
    if(s == e){
        printf("Depot %d at restaurant %d serves restaurant %d\n", h, (s+e)/2, s);
    } else {
        printf("Depot %d at restaurant %d serves restaurants %d to %d\n", h, (s+e)/2, s, e);
    }
}
int main(){
    //freopen("output.txt", "w", stdout);
    while(true){

        memset(dp, INF, sizeof(dp));
        memset(dp[0], 0, sizeof(dp[0]));
        memset(d, 0, sizeof(d));
        memset(distances, 0, sizeof(distances));
        memset(first, 0, sizeof(first));
        scanf("%d%d", &n, &k);
        if(!n && !k){
            break;
        }

        for(int i = 1; i<=n; i++){
            scanf("%d", d + i);
        }

        for(int i = 1; i<=n; i++){
            for(int j = i+1; j<=n; j++){
                int mid = (i+j)/2;
                for(int k = i; k<=j; k++){
                    distances[i][j] += abs(d[mid] - d[k]);
                }
            }
        }
        //dp[numHouses][numDepots]
        for(int e = 1; e<=n; e++){
            for(int h = 1; h<=k; h++){
                for(int s = 1; s<=e; s++){
                    int newCost = dp[s-1][h-1] + distances[s][e];
                    if(newCost < dp[e][h]){
                        dp[e][h] = newCost;
                        first[e][h] = s;
                    }
                }
            }
        }

        printf("Chain %d\n", ++c);
        printHouses(n, k);
        printf("Total distance sum = %d\n", dp[n][k]);   
        printf("\n");
    }
}
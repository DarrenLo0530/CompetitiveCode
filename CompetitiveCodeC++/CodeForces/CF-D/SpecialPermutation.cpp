#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i<t; i++){
        int n;
        scanf("%d", &n);
        if(n <= 3){
            printf("-1\n");
            continue;
        }
        int start = n % 2 == 0 ? n - 1 : n;
        for(int i = start; i >= 1; i-=2){
            if(i != start){
                printf(" ");
            }
            printf("%d", i);
        }
        printf(" 4 2");
        for(int i = 6; i<=n; i+=2){
            printf(" %d", i);
        }
        printf("\n");
    }
}
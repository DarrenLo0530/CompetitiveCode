#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int MX = 405;
char layout[MX][MX];

int psah[MX][MX];

int main(){
    int r, c;
    scanf("%d%d", &r, &c);

    for(int i = 0; i<r; i++) {
        for(int j = 0; j<c; j++) {
            scanf(" %c", &layout[i][j]);
        }
    }

    for(int i = 0; i<r; i++) {
        for(int j = c-1; j>=0; j--) {
            if(layout[i][j] != 'X') { 
                psah[i][j] = psah[i][j+1] + 1;
            }
        }
    }

    int ans = 0;

    for(int i = 0; i<r; i++) {
        for(int j = 0; j<c; j++) {
            int rowSize = INF;
            for(int k = i; k<r; k++) {
                if(layout[k][j] == 'X') {
                    break;
                }
                
                rowSize = min(rowSize, psah[k][j]);
                ans = max(ans, (k - i + 1)*2 + rowSize*2);
            }
        }
    }
    printf("%d\n", ans-1);
}
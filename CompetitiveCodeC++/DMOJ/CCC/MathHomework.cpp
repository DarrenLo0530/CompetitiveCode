#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int MX = 150010;
int x[MX], y[MX], z[MX];

int n, m;
    

int main(){
    scanf("%d%d", &n, &m);
    
    vector<int> ans(n+5, 1);
    for(int i = 0; i<m; i++) {
        scanf("%d%d%d", &x[i], &y[i], &z[i]);
        if(z[i] == 2) {
            for(int j = x[i]; j<=y[i]; j++) {
                ans[j] = 2;
            }
        }
    }


    for(int i = 0; i<m; i++) {
        if(z[i] == 1) {
            bool hasOne = false;
            for(int j = x[i]; j<=y[i]; j++) {
                if(ans[j] == 1) {
                    hasOne = true;
                }
            }

            if(!hasOne) {
                printf("Impossible\n");
                return 0;
            }
        }
    }

    for(int i = 1; i<=n; i++) {
        if(i != 1) {
            printf(" %d", ans[i]);
        } else {
            printf("%d", ans[i]);
        }
    }
    printf("\n");

}
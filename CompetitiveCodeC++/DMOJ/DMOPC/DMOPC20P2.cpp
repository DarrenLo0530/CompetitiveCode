#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int a[1000001], psa[1000001];
int main(){
    int N, D;
    scanf("%d%d", &N, &D);
    for(int i = 1; i<=N; i++){
        scanf("%d", a + i);
    }

    for(int i = 1; i<=N; i++){
        psa[i] = psa[i-1] + a[i];
    }

    int l = 1;
    int r = N;
    for(int i = 0; i<D; i++){
        int n;
        scanf("%d", &n);

        int m = l + n -1;
        int lSum = psa[m] - psa[l-1];
        int rSum = psa[r] - psa[m];

        if(lSum >= rSum){
            printf("%d\n", lSum);
            l = m+1;
        } else {
            printf("%d\n", rSum);
            r = m;
        }
    }
}
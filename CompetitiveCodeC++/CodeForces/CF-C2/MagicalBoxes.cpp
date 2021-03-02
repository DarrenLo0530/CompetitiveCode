#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const int MX = 100001;

int main(){
    int n;
    scanf("%d", &n);
    int p = 0;
    int maxSize = 0;
    for(int i = 0; i<n; i++){
        int k, a;
        scanf("%d%d", &k, &a);
        maxSize = max(maxSize, k);
        p = max(p, k + (int) ceil(log(a)/log(4)));

    }

    if(p == maxSize){
        p++;
    }

    printf("%d\n", p);

}
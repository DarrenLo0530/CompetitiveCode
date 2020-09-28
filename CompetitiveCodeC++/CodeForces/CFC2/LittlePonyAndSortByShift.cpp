#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int a[100001];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d", a + i);
    }

    int cnt = 0;
    int idx = n;

    //Asscending 2 3 1 1 4 - 2
    for(int i = 1; i<n; i++){
        if(a[i] < a[i-1]){
            cnt++;
            idx = i;
        }
    }

    if(cnt > 1 || (cnt == 1 && a[0] < a[n-1])){
        printf("-1\n");
    } else {
        printf("%d\n", n - idx);
    }
}
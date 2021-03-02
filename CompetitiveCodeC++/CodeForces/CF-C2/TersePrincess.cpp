#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int p2[100];

int main(){
    p2[0] = 1;
    for(int i = 1; i<20; i++){
        p2[i] = p2[i-1] * 2;
    }

    vector<int> ans;
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    if(b > (int) log2(50000) || p2[b] + a > 50000 || a != 0 && b == 0 && a+2 > n){
        printf("-1\n");
        return 0;
    }
    
    ans.push_back(1);
    if(b == 0){
        for(int i = 0; i<n-a-b-1; i++){
            ans.push_back(1);
        }
    }
    for(int i = 1; i<=b; i++){
        ans.push_back(p2[i]);
    }

    for(int j = 1; j<=a; j++){
        ans.push_back(p2[b] + j);
    }

    if(b != 0){
        for(int i = 0; i<n-a-b-1; i++){
            ans.push_back(1);
        }
    }
    
    for(int i = 0; i<ans.size(); i++){
        if(i != 0){
            printf(" ");
        }
        printf("%d", ans[i]);
    }
    printf("\n");
}
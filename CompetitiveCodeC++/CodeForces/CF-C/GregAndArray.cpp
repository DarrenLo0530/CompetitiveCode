#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Operation {
    int l, r, d;
};

ll nums[100005];
ll da[100005];
Operation operations[100005];
ll operationCount[100005];

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    for(int i = 1; i<=n; i++){
        scanf("%lld", nums + i);
    }

    for(int i = 1; i<=m; i++){
        int l, r, d;
        scanf("%d%d%d", &l, &r, &d);
        operations[i] = Operation{l, r, d};
    }

    for(int i = 0; i<k; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        operationCount[x]++;
        operationCount[y+1]--;
    }
   
    for(int i = 1; i<=m; i++){
        operationCount[i] += operationCount[i-1];
        da[operations[i].l] += operationCount[i] * operations[i].d;
        da[operations[i].r + 1] -= operationCount[i] * operations[i].d;
    }

    for(int i = 1; i<=n; i++){
        da[i] += da[i-1];
        nums[i] += da[i];
        if(i != 1){
            cout<<" ";
        }
        cout<<nums[i];
    }

    cout<<'\n';

    
}
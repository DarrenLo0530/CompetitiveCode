#include <bits/stdc++.h>
using namespace std;

int idx1[100005];
int exited[100005];

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 1; i<=n; i++){
        int a;
        scanf("%d", &a);
        idx1[a] = i;
    }

    for(int i = 1; i<=n; i++){
        int a;
        scanf("%d", &a);
        exited[i] = a;
    }

    int ans = 0;
    int minIdx = 0x3f3f3f3f;

    for(int i = n; i>=1; i--){
        if(idx1[exited[i]] > minIdx){
            ans++;
        }
        
        minIdx = min(minIdx, idx1[exited[i]]);
    }

    cout<<ans;

}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100001];
int main(){
    int n, x;
    scanf("%d%d", &n, &x);
    ll minVal = 0x3f3f3f3f;
    for(int i = 1; i<=n; i++){
        scanf("%d", a+i);
        minVal = min(minVal, a[i]);
    }

    ll starting = minVal * n;
    for(int i = 1; i<=n; i++){
        a[i] -= minVal;
    }
    //We know that we went around atleast minVal times since we added a ball minVal times to the starting pos and starting pos was 0.

    //Now we know after going around minVal times, we end up at index startPos + 1 again. We ended up at index x. Therefore we added an extra ball for every box
    //between index startPos + 1 and x.
    //We know that if a box has 0 balls, that means we couldn't have added an extra ball there since it got all it's balls from the minVal cycles we went around
    //Therefore, it must be that box must be the startPos.
    int currIdx = x;
    while(a[currIdx]){
        a[currIdx]--;
        starting++;
        currIdx = (currIdx - 2 + n) % n + 1;
    }
    a[currIdx] = starting;

    for(int i = 1; i<=n;i++){
        if(i != 1){
            cout<<" ";
        }
        cout<<a[i];
    }

    cout<<'\n';
}
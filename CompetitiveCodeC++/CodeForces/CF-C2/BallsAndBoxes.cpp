#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100001];
int main(){
    int n, x;
    scanf("%d%d", &n, &x);

    ll minVal = 0x3f3f3f3f;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
        minVal = min(a[i], minVal);
    }

    set<int> pos;
    int last = 0;
    for(int i = 1; i<=n; i++){
        if(a[i] == minVal){
            pos.insert(i);
            last = i;
        }
    }

    auto removedElem = pos.upper_bound(x);
    int minIdx;
    if(removedElem == pos.begin()){
        minIdx = last;
    } else {
        minIdx = *--removedElem;
    }

    ll extra = ((n-minIdx + x) % n);
    a[minIdx] = n*minVal + extra;
    int currIdx = (minIdx % n) + 1;
    while(currIdx != minIdx){
        a[currIdx] -= minVal;
        if(extra-- > 0){
            a[currIdx]--;
        }
        currIdx = (currIdx) % n + 1;
    }

    for(int i = 1; i<=n; i++){
        if(i != 1){
            cout<<" ";
        }
        cout<<a[i];
    }

    cout<<"\n";
}
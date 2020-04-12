#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int st[(1<<20)];

void add(int idx){
    idx = idx - 1 + (1<<19);

    while(idx != 0){
        st[idx] ++;
        idx = idx/2;
    }
}

int getRangeSum(int l, int r){
    l = l - 1 + (1<<19);
    r = r - 1 + (1<<19);
    int ans = 0;
    while(l <= r && l != 0 && r != 0){
        if(l % 2 != 0){
            ans += st[l];
            l += 1;
        } 
        if(r % 2 == 0){
            ans += st[r];
            r -= 1;
        }

        l = l/2;
        r = r/2;
    }

    return ans;
}

int main(){
    queue<int> nums;

    int N, a;
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%d", &a);
        nums.push(a);
    }

    ll inversions = 0;

    while(!nums.empty()){
        int curr = nums.front();
        nums.pop();
        
        add(curr);
        //Placed at front
        //Add number smaller than new number
        int inv1 = getRangeSum(1, curr-1);

        //Placed at back
        int inv2 = getRangeSum(curr+1, 500000);
        if(inv1 <= inv2){
            inversions += inv1;
        } else {
            inversions += inv2;
        }
        
    }

    cout<<inversions;
}
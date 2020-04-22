#include <bits/stdc++.h>
#define mx 1000000
#define INF 0x3f3f3f3f

using namespace std;
int nums[mx+1];


int minL = 1, maxR = 1;


int binSearch(int l, int r, int val){
    int mid = (l+r)/2;
    if(l == r){
        if(val <= nums[l]){
            return l;
        } else {
            return l+1;
        }
    } else if(val > nums[mid]){
        return binSearch(mid+1, r, val);
    } else {
        return binSearch(l, mid, val);
    }
}

int main(){
    int N, a;
    nums[1] = INF;

    scanf("%d", &N);

    for(int i = 0; i<N; i++){
        scanf("%d", &a);
        int newIdx = binSearch(minL, maxR, a);
        if(newIdx > maxR){
            maxR = newIdx;
        }

        nums[newIdx] = a;
    }

    cout<<maxR;
}
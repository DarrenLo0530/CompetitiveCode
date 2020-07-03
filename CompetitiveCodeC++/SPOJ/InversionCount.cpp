#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int data[200002];

ll merge(int l, int mid, int r){
    int lArrayLength = mid - l + 1;
    int rArrayLength = r - mid;
    int lArray[lArrayLength] = {0};
    int rArray[rArrayLength] = {0};

    copy(data+l, data + mid + 1, lArray);
    copy(data+mid+1, data+r+1, rArray);

    int lCounter = 0;
    int rCounter = 0;
    ll inversions = 0;

    while(lCounter < lArrayLength && rCounter < rArrayLength){
        if(lArray[lCounter] <  rArray[rCounter]){
            data[lCounter + rCounter + l] = lArray[lCounter];
            lCounter++;
        } else {
            data[lCounter + rCounter + l] = rArray[rCounter];
            inversions += lArrayLength - lCounter;
            rCounter++;
        }
    }

    while(lCounter < lArrayLength){
        data[lCounter + rCounter + l] = lArray[lCounter];
        lCounter++;
    }

    while(rCounter < rArrayLength){
        data[lCounter + rCounter + l] = rArray[rCounter];
        rCounter++;
    }

    return inversions;
}

ll mergeSort(int l, int r){
    if (l == r){
        return 0;
    }

    int mid = (l+r)/2;
    ll leftInversions = mergeSort(l, mid);
    ll rightInversions = mergeSort(mid+1, r);
    ll newInversions = merge(l, mid, r);

    return leftInversions + rightInversions + newInversions;
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){ 
        memset(data, 0, sizeof(data));
        int n;
        scanf("%d", &n);

        for(int i = 1; i<=n; i++){
            scanf("%d", data + i);
        }

        cout<<mergeSort(1, n) << '\n';
    }
}